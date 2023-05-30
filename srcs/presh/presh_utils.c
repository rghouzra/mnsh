/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presh_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:12:59 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/26 16:29:42 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	update_paths(void)
{
	char	*tmp;
	int		i;

	i = -1;
	while (g_mnsh->paths_list[++i])
	{
		tmp = my_string_join(g_mnsh->paths_list[i], "/");
		if (!tmp)
			return (-1);
		if (my_string_update(&(g_mnsh->paths_list[i]), tmp) == -1)
			return (-1);
		free(tmp);
		tmp = (char *)0;
	}
	return (0);
}

static int	addpaths(char *paths)
{
	g_mnsh->paths_list = my_string_split(paths, ":");
	if (!(g_mnsh->paths_list))
		return (-1);
	if (update_paths() == -1)
		return (-1);
	return (0);
}

int	contruipaths(void)
{
	t_my_list	*it;

	it = g_mnsh->env_list;
	while (it)
	{
		if (my_string_compare(((char **)it->data)[0], "PATH") == LS_EQUAL)
		{
			if (addpaths(((char **)it->data)[1]) == -1)
				return (perror("mnsh::"), -1);
		}
		it = it->next;
	}
	return (0);
}
