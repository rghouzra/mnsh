/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:01:02 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/21 04:18:24 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	heredoc_handler(int sig)
{
	(void)sig;
	g_mnsh->_break = 1;
}

int	check_delim_expansion(char **line, int	*flag)
{
	t_delim_expand	packed;
	
	if (line == NULL || *line == NULL)
		return (-1);
	packed.lines =  ft_alphasplit2(*line, '\0', (t_alphasplit){0, 0, 0, 0,0, 0,0, 0,0});
	remove_quotes_2(line);
	*flag = (my_strings_count(packed.lines) == 1 && packed.lines[0][0] != '\'' && packed.lines[0][0] != '"');
	return (ft_free(packed.lines), 0);
}

int readheredoc_init(t_read_heredoc *var, char **delimiter)
{
	check_delim_expansion(delimiter, &var->flag_expansion);
	var->ptr = *delimiter;
	var->line = NULL;
	return var->flag_expansion;
}
char	*read_heredoc(char *delimiter)
{
	t_read_heredoc	x;

	if (readheredoc_init(&x, &delimiter) == -1)
		return (NULL);
	x.name = generate_filename();
	x.fd = ft_open(x.name, O_CREAT | O_RDWR | O_TRUNC, 0644, &g_mnsh->exit_status);
	if (ft_fork() == 0)
	{
		signal(SIGINT, heredoc_handler);
		while (g_mnsh->_break == 0)
		{
			x.line = readline("> ");
			if (!x.line || !ft_strcmp(x.line, delimiter))
				break;
			my_string_append_char(&x.line, '\n');
			if(x.flag_expansion)
				expand(&x.line);
			write(x.fd, x.line, ft_strlen(x.line));
			free(x.line);
		}
		exit(0);
	}
	return (waitpid(-1, 0, 0), free(x.line), free(x.ptr), close(x.fd), x.name);
}
