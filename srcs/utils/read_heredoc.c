/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:01:02 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/12 16:20:00 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void read_heredoc(char *delemiter)
{
	char *line;
	int fd;

	if(!delemiter)
		return ;
	fd = open("/tmp/heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if(fd == -1)
		return ;
	while(1)
	{
		line = readline("> ");
		if(!line)
			break ;
		if(!ft_strcmp(line, delemiter))
			break ;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
	}
	close(fd);
}