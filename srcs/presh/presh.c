/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:15:54 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/24 23:03:03 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "footer/presh.h"

extern t_minishell	*g_minishell;

int	addenv(char *ev)
{
	char	**key_value;
	int		index;

	key_value = (char **)malloc(sizeof(char *) * 2);
	if (!key_value)
		return (perror("mnsh::"), -1);
	index = my_string_find_first(ev, "=");
	key_value[0] = my_string_sub(ev, 0, index);
	key_value[1] = my_string_sub(ev, index+1, my_string_len(ev) - index - 1);
	printf("%s\n-> |%s|=|%s|\n",ev, key_value[0], key_value[1]);
	if (my_list_push_back(&(g_minishell->env_list), my_list_new_elem((void *)key_value)) == -1)
		return (perror("mnsh::"), exit(EXIT_FAILURE), -1);
	return (0);
}

int	presh(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (addenv(env[i]) == -1)
			return (-1);
	return (0);
}
