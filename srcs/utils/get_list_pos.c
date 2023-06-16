/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:18:58 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/15 17:21:47 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	get_arg_pos(t_my_list *it, char *arg)
{
	int	i;

	i = 0;
	while (it)
	{
		if (my_string_compare(*((char **)it->data), arg) == LS_EQUAL)
			return (i);
		it = it->next;
		i++;
	}
	return (-1);
}
