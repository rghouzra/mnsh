/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:21:11 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/29 17:40:24 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void	env(void)
{
	t_my_list	*it;

	it = g_mnsh->env_list;
	while (it)
	{
		printf("%s=%s\n", ((char **)it->data)[0], ((char **)it->data)[1]);
		it = it->next;
	}
	exit(EXIT_SUCCESS);
}
