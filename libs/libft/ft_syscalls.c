/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscalls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 08:57:46 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/20 15:21:03 by rghouzra         ###   ########.fr       */
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

int	ft_open(char *filename, int flags, int permission, int *exit_status)
{
	int	fd;

	fd = open(filename, flags, permission);
	if (fd == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		*exit_status = 1;
	}
	return (fd);
}
