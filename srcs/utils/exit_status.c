/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:55:55 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/21 17:12:22 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	exit_status(int status, int mode)
{
	if (mode == YES_EXIT)
		exit(status);
	g_mnsh->exit_status = status;
	return (status);
}

int	get_the_exitstatus(void)
{
	if (WIFEXITED(g_mnsh->exit_status))
		return (WEXITSTATUS(g_mnsh->exit_status));
	else if (WIFSIGNALED(g_mnsh->exit_status))
		return (WTERMSIG(g_mnsh->exit_status) + 128);
	else
		return (1);
}
