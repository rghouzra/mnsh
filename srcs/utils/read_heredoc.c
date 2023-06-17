/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:01:02 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/17 13:27:43 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*read_heredoc(char *delemiter)
{
	char *line;
	int fd;
	char *name;

	if(!delemiter)
		return NULL;
	name = generate_filename();
	fd = ft_open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if(ft_fork() == 0)
	{
		signal(SIGINT, SIG_DFL);
		while(1)
		{
			line = readline("> ");
			if(!line)
				break ;
			if(!ft_strcmp(line, delemiter))
				break ;
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
		exit(0);
	}
	return (waitpid(0, 0, 0), close(fd), name);
}
