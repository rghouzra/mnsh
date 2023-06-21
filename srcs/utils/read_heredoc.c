/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:01:02 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/21 01:01:07 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	heredoc_handler(int sig)
{
	(void)sig;
	g_mnsh->_break = 1;
}

int	check_delim_expansion(char **line)
{
	t_delim_expand	packed;
	
	if (line == NULL || *line == NULL)
		return (-1);
	packed.i = -1;
	packed.flag = 0;
	packed.lines =  ft_alphasplit2(*line, '\0', (t_alphasplit){0, 0,0, 0,0, 0,0, 0,0});
	while(packed.lines[++packed.i])
	{
		packed.j = -1;
		packed.dollar = 0;
		packed.c = packed.lines[packed.i][0];
		while(packed.lines[packed.i][++packed.j])
			packed.dollar += (packed.lines[packed.i][packed.j] == '$');
		packed.flag += (!packed.dollar) + ((packed.dollar >= 1) \
		 - ( +(packed.c == DQ) + (packed.c == SQ) - (!packed.dollar)));
	}
	ft_free(packed.lines);
	remove_quotes_2(line);
	return packed.flag >= packed.i;
}

int readheredoc_init(t_read_heredoc *var, char **delimiter)
{
	var->flag_expansion = check_delim_expansion(delimiter);
	var->ptr = *delimiter;
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
			if(x.flag_expansion)
				expand(&x.line);
			ft_putendl_fd(x.line, x.fd);
			free(x.line);
		}
		exit(0);
	}
	return (x.line = NULL, waitpid(-1, 0, 0), free(x.line), free(x.ptr), close(x.fd), x.name);
}
