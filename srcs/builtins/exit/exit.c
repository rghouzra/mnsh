/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:34:48 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/01 00:51:57 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void	mnsh_exit(int ac, char **av, int status)
{
	if (ac > 2)
	{
		printf("exit::too many arguments\n");
		g_mnsh->exit_status = EXIT_FAILURE;
		if (status == YES_EXIT)
			exit(EXIT_FAILURE);
		g_mnsh->exit_status = EXIT_FAILURE;
		return ;
	}
	if (ac == 1)
		exit(EXIT_SUCCESS);
	exit(ft_atoi(av[1]));
}
