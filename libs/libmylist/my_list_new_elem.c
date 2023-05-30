/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_new_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:24:08 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/31 00:09:58 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

t_my_list	*my_list_new_elem(void *data, void (*data_clear)(void **))
{
	t_my_list	*new;

	if (!data)
		return ((t_my_list *)0);
	new = (t_my_list *)malloc(sizeof(t_my_list));
	if (!new)
		return (data_clear(&data), (t_my_list *)0);
	new->data = data;
	new->next = (t_my_list *)0;
	return (new);
}
