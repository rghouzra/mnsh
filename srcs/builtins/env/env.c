/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:21:11 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/31 15:17:34 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void	env(int status)
{
	t_my_list	*it;
	(void)status;

	it = g_mnsh->env_list;
	while (it)
	{
		printf("%s=%s\n", ((char **)it->data)[0], ((char **)it->data)[1]);
		it = it->next;
	}
	exit(EXIT_SUCCESS);
}
