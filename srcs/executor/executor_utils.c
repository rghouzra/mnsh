/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:43:03 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/29 16:50:57 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*execute( char **cmnds)
{
	char	*cmd;

	if (!cmnds || !*cmnds)
		return (NULL);
	ifbuiltinbreak(cmnds);
	cmd = getcmdfullpath(*cmnds);
	if (!cmnds)
		show_error(strerror(errno), 1);
	execve(cmd, cmnds, NULL);
	show_error(strerror(errno), 127);
	return (NULL);
}

int	check_access(char *path, int which)
{
	if (which == 0)
	{
		if (!(access(path, R_OK)))
			return (open(path, O_RDONLY));
	}
	else if (which == 1)
	{
		if (!(access(path, F_OK)))
			return (1);
	}
	else if (which == 3)
	{
		if (!(access(path, X_OK)))
			return (1);
	}
	return (-1);
}
