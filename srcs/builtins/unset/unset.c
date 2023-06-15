/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:06:04 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/15 17:29:42 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	unset_arg(char *arg)
{
	if (!is_keyvalid(arg))
		return (-1);
	if (env_var_exist(arg))
		my_list_erase(&g_mnsh->env_list, get_arg_pos(g_mnsh->env_list, arg),
				my_list_data_clear);
	if (export_var_exist(arg))
		my_list_erase(&g_mnsh->export_list, get_arg_pos(g_mnsh->export_list,
					arg), my_list_data_clear);
	return (0);
}

int	unset(int ac, char **av, int mode)
{
	int	f;
	int	i;

	f = EXIT_SUCCESS;
	i = 0;
	while (++i < ac)
		if (unset_arg(av[i]) == -1)
		{
			f = EXIT_FAILURE;
			printf("unset::'%s' is not a valid identifier\n", av[i]);
		}
	return (exit_status(f, mode));
}
