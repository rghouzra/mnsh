/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:12:16 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/16 13:38:33 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	change_dir(char *dir)
{
	printf("going to dir '%s'\n", dir);
	return (0);
}

int	cd(int ac, char **av, int mode)
{
	if (ac > 1)
		if (change_dir(av[1]) == -1)
			return (exit_status(EXIT_FAILURE, mode));
	return (exit_status(EXIT_SUCCESS, mode));
}

/*

	Functions :
				getcwd
				chdir

	Tasks	 :
				contruir path.
				chdir.
				update pwd.
				update env-export.


*/
