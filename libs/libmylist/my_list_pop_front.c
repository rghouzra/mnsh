/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_pop_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:02:34 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/10 21:54:35 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

int	my_list_pop_front(t_my_list **list)
{
	t_my_list	*iterator;

	if (!list)
		return (-1);
	if (my_list_empty(*list))
		return (0);
	iterator = *list;
	*list = iterator->next;
	return (free(iterator->data), free(iterator), 0);
}
