/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:39:12 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/07 17:39:57 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	export_var_update(char *key, char *new_value)
{
	t_my_list *it;

	it = g_mnsh->export_list;
	while (it)
	{
		if (my_string_compare(((char **)it->data)[0], key) == LS_EQUAL)
		{
			if (my_string_update(&(((char **)it->data)[1]), new_value) == -1)
				return (-1);
			return (0);
		}
		it = it->next;
	}
	return (0);
}
