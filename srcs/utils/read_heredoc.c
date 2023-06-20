/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:01:02 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/20 20:49:26 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	heredoc_handler(int sig)
{
	(void)sig;
	g_mnsh->_break = 1;
}

char	*read_heredoc(char *delimiter)
{
	char	*line;
	int		fd;
	char	*name;

	if (!delimiter)
		return (NULL);
	name = generate_filename();
	fd = ft_open(name, O_CREAT | O_RDWR | O_TRUNC, 0644, &g_mnsh->exit_status);
	if (ft_fork() == 0)
	{
		signal(SIGINT, heredoc_handler);
		while (g_mnsh->_break == 0)
		{
			line = readline("> ");
			if (!line || !ft_strcmp(line, delimiter))
				break;
			ft_putendl_fd(line, fd);
			free(line);
			
		}
		exit(0);
	}
	return (line = NULL, waitpid(-1, 0, 0), free(line), close(fd), name);
}
