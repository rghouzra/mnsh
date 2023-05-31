/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:43:03 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/31 15:16:10 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

char	*execute(char **cmnds)
{
	char	*cmd;
	char	**ev;

	if (!cmnds || !*cmnds)
		return (NULL);
	ifbuiltinbreak(cmnds, 0);
	cmd = getcmdfullpath(*cmnds);
	if (!cmnds)
		show_error(strerror(errno), 1);
	ev = contrui_env();
	execve(cmd, cmnds, ev);
	show_error(strerror(errno), 127);
	return (my_strings_free(&ev), NULL);
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
