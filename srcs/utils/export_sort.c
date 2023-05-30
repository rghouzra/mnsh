/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:44:32 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/26 18:16:47 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static void	swapstep(void)
{
	t_my_list	*it;

	it = g_mnsh->export_list;
	while (it->next)
	{
		if (my_string_compare(((char **)it->data)[0],
				((char **)it->next->data)[0]) == LS_GREAT)
			my_string_swap(&((char **)it->data)[0],
					&((char **)it->next->data)[0]);
		it = it->next;
	}
}

void	export_sort(void)
{
	t_my_list	*it;

	it = g_mnsh->export_list;
	while (it)
	{
		swapstep();
		it = it->next;
	}
}
