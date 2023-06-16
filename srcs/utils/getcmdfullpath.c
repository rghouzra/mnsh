/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcmdfullpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:54:31 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/16 14:10:44 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

char	*getcmdfullpath(char *cmd)
{
	char	*path;
	int		i;

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
