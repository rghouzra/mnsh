/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_new_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:24:08 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/18 23:48:28 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

t_my_list	*my_list_new_elem(void *data)
{
	t_my_list	*new;

	if (!data)
		return ((t_my_list *)0);
	new = (t_my_list *)malloc(sizeof(t_my_list));
	if (!new)
		return (free(data), data = NULL, (t_my_list *)0);
	new->data = data;
	new->next = (t_my_list *)0;
	return (new);
}
