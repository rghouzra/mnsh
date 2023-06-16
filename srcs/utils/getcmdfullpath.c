/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcmdfullpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:54:31 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/16 15:59:49 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

char	*getcmdfullpath(char *cmd)
{
	char	*path;
	int		i;

	if (my_string_find_first(cmd, "/") > -1)
	{
		path = my_string_dup(cmd);
		if (!path)
			return (ft_putstr_fd("mnsh::malloc failed\n", STDERR_FILENO), NULL);
		return (path);
	}
	if (!(g_mnsh->paths_list))
		return (NULL);
	i = -1;
	path = (char *)0;
	while (g_mnsh->paths_list[++i])
	{
		path = my_string_join(g_mnsh->paths_list[i], cmd);
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		path = (char *)0;
	}
	return (NULL);
}
