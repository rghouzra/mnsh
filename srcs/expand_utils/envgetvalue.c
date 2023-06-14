/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envgetvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:17:08 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/13 15:47:09 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

char	*envgetvalue(char *key)
{
	t_my_list	*it;

	it = g_mnsh->env_list;
	while (it)
	{
		if (my_string_compare(((char **)it->data)[0], key) == LS_EQUAL)
			return (((char **)it->data)[1]);
		it = it->next;
	}
	return (NULL);
}
