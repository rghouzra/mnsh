/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_erase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:35:43 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/10 21:28:37 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

int	my_list_erase(t_my_list **list, long long index)
{
	t_my_list	*iterator;
	t_my_list	*prev;
	long long	i;

	if (index < 0 || !list || my_list_empty(*list))
		return (-1);
	if (index == 0)
		return (my_list_pop_front(list));
	iterator = *list;
	i = 0;
	while (iterator->next)
	{
		if (i == index)
			break ;
		prev = iterator;
		iterator = iterator->next;
		i++;
	}
	if (i != index)
		return (-1);
	prev->next = iterator->next;
	return (free(iterator->data), free(iterator), 0);
}
