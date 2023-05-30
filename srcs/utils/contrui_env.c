/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contrui_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:01:34 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/30 11:19:14 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static void	free_ev(char ***ev)
{
	int	i;

	i = -1;
	while ((*ev)[++i])
		free((*ev)[i]);
	free(*ev);
	*ev = 0;
}

static char	*take_ev(char **data)
{
	char	*r;

	r = my_string_join(data[0], "=");
	if (!r)
		return (NULL);
	if (my_string_append(&r, data[1]) == -1)
		return (free(r), NULL);
	return (r);
}

char	**contrui_env()
{
	t_my_list	*it;
	char		**ev;
	int			i;

	if (!(g_mnsh->env_list))
		return (NULL);
	ev = (char **)ft_malloc(sizeof(char *) * (my_list_size(g_mnsh->env_list)
				+ 1));
	it = g_mnsh->env_list;
	i = -1;
	while (it)
	{
		ev[++i] = take_ev((char **)it->data);
		if (!ev[i])
			return (free_ev(&ev), NULL);
		it = it->next;
	}
	return (ev[i] = NULL, ev);
}
