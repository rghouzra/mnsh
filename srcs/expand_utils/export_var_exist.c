/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_exist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:33:45 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/17 18:42:04 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	export_var_exist(char *key)
{
	t_my_list	*it;

	it = g_mnsh->export_list;
	while (it)
	{
		if (my_string_compare(key, ((char **)it->data)[0]) == LS_EQUAL)
			return (1);
		it = it->next;
	}
	return (0);
}
