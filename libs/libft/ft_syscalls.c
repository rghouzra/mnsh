/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscalls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 08:57:46 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/19 15:33:17 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <string.h>

void	ft_pipe(int fd[])
{
	if (pipe(fd) == -1)
		show_error(strerror(errno), 1);
}

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		show_error(strerror(errno), 1);
	return (pid);
}

int	ft_open(char *filename, int flags, int permission)
{
	int	fd;

	if (permission)
		fd = open(filename, flags, permission);
	else
		fd = open(filename, flags);
	if(fd == -1)
		show_error(strerror(errno), 126);
	if (fd == -1)
		show_error(strerror(errno), 1);
	return (fd);
}
