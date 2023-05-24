/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_pop_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:05:14 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/10 21:50:58 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

static int	my_static_list_size(t_my_list *list)
{
	t_my_list	*iterator;
	int			size;

	size = 0;
	iterator = list;
	if (my_list_empty(list))
		return (size);
	while (size < 2 && iterator)
	{
		iterator = iterator->next;
		size++;
	}
	return (size);
}

int	my_list_pop_back(t_my_list **list)
{
	t_my_list	*iterator;
	int			size;

	if (!list)
		return (-1);
	size = my_static_list_size(*list);
	if (size == 0)
		return (0);
	else if (size == 1)
		my_list_clear(list);
	else
	{
		iterator = *list;
		while (iterator->next->next)
			iterator = iterator->next;
		free(iterator->next->data);
		free(iterator->next);
		iterator->next = (t_my_list *)0;
	}
	return (0);
}
