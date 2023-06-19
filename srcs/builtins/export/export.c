/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:08:01 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/15 18:37:55 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	add_to_export(char **kv)
{
	if (export_var_exist(kv[0]))
	{
		if (kv[1] && export_var_update(kv[0], kv[1]) == -1)
			return (my_strings_free_count(&kv, 2), -1);
		return (0);
	}
	if (my_list_push_back(&g_mnsh->export_list, my_list_new_elem(my_strings_dup_count(kv, 2),
				&my_list_data_clear)) == -1)
		return (-1);
	return (export_sort(), 0);
}

static int	add_to_env(char **kv)
{
	if (env_var_exist(kv[0]))
	{
		if (kv[1] && env_var_update(kv[0], kv[1]) == -1)
			return (my_strings_free_count(&kv, 2), -1);
		return (0);
	}
	if (kv[1] && (my_list_push_back(&g_mnsh->env_list,
				my_list_new_elem(my_strings_dup_count(kv, 2),
					&my_list_data_clear)) == -1))
		return (-1);
	return (0);
}

static int	export_var(char *av)
{
	char	**kv;

	kv = my_string_split_by_first(av, "=");
	if (!kv)
		return (-1);
	if (!is_keyvalid(kv[0]))
		return (my_strings_free_count(&kv, 2), -1);
	if (add_to_export(kv) == -1)
		return (my_strings_free_count(&kv, 2), -1);
	if (kv[1] && add_to_env(kv) == -1)
		return (my_strings_free_count(&kv, 2), -1);
	return (my_strings_free_count(&kv, 2), 0);
}

void	export(int ac, char **av, int mode)
{
	int	i;
	int	f;

	f = EXIT_SUCCESS;
	i = 0;
	if (ac == 1)
		print_export();
	while (++i < ac)
		if (export_var(av[i]) == -1)
		{
			f = EXIT_FAILURE;
			printf("export: %s: not a valid identifier\n", av[i]);
		}
	exit_status(f, mode);
}
