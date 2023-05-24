/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscalls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 08:57:46 by rghouzra          #+#    #+#             */
/*   Updated: 2023/03/23 20:53:18 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_pipe(int fd[])
{
	if(pipe(fd) == -1)
		show_error(strerror(errno), 1);
}

pid_t ft_fork()
{
	pid_t pid;

	pid = fork();
	if(pid == -1)
		show_error(strerror(errno), 1);
	return (pid);
}
