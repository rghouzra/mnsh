/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:15:54 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/26 15:37:46 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	addpaths(char *paths)
{
	g_mnsh->paths_list = my_string_split(paths, ":");
	if (!(g_mnsh->paths_list))
		return (-1);
	return (0);
}

static int	contruipaths()
{
	t_my_list *it;

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

static int	addenvto(char *ev, t_my_list **list)
{
	char	**key_value;
	int		index;

	key_value = (char **)ft_malloc(sizeof(char *) * 2);
	if (!key_value)
		return (perror("mnsh::"), -1);
	index = my_string_find_first(ev, "=");
	key_value[0] = my_string_sub(ev, 0, index);
	key_value[1] = my_string_sub(ev, index+1, my_string_len(ev) - index - 1);
	if (my_list_push_back(list, my_list_new_elem((void *)key_value)) == -1)
		return (perror("mnsh::"), exit(EXIT_FAILURE), -1);
	return (0);
}

static int	addenv(char *ev)
{
	if (addenvto(ev, &(g_mnsh->export_list)) == -1)
		return (-1);
	if (addenvto(ev, &(g_mnsh->env_list)) == -1)
		return (-1);
	return (0);
}

int	presh(char **env)
{
	int	i;

	g_mnsh->env_list = 0;
	g_mnsh->paths_list = 0;
	g_mnsh->export_list = 0;
	g_mnsh->exit_status = 0;
	i = -1;
	while (env[++i])
		if (addenv(env[i]) == -1)
			return (-1);
	if (contruipaths() == -1)
		return (-1);
	return (0);
}
