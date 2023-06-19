/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:44:32 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/15 14:53:55 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static void	swapstep(void)
{
	t_my_list	*it;
	void		*tmp;

	it = g_mnsh->export_list;
	while (it->next)
	{
		if (my_string_compare(((char **)it->data)[0],
				((char **)it->next->data)[0]) == LS_GREAT)
		{
			tmp = it->data;
			it->data = it->next->data;
			it->next->data = tmp;
		}
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
