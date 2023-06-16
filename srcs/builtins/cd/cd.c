/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:12:16 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/16 17:28:05 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	change_dir(char *dir)
{
	char *new;

	new = (char *)0;
	if (dir)
	{
		new = my_string_dup(dir);
		if (!new)
			return (perror("mnsh::cd::"), -1);
	}
	if (my_string_append_char(&new, '/') == -1)
		return (free(new), perror("mnsh::cd"), -1);
	if (chdir(new) == -1)
		return (free(new), perror("mnsh::cd::"), -1);
	return (free(new), 0);
}

int	cd(int ac, char **av, int mode)
{
	if (ac > 1)
	{
		if (change_dir(av[1]) == -1)
			return (exit_status(EXIT_FAILURE, mode));
	}
	else
		if (change_dir(NULL) == -1)
			return (exit_status(EXIT_FAILURE, mode));
	return (exit_status(EXIT_SUCCESS, mode));
}
