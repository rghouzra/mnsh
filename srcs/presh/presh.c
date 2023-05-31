/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:15:54 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/31 17:05:29 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	addenvto(char *ev, t_my_list **list)
{
	char	**key_value;

	key_value = my_string_split_by_first(ev, "=");
	if (my_list_push_back(list, my_list_new_elem((void *)key_value, &my_list_data_clear)) == -1)
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

	my_list_init(&(g_mnsh->env_list));
	my_list_init(&(g_mnsh->export_list));
	g_mnsh->paths_list = 0;
	g_mnsh->exit_status = 0;
	i = -1;
	while (env[++i])
		if (addenv(env[i]) == -1)
			return (-1);
	if (contruipaths() == -1)
		return (-1);
	return (0);
}
