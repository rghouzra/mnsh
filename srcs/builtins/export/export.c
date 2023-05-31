/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:08:01 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/31 16:34:42 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

// static void	print_export(void)
// {
// 	t_my_list	*it;

// 	it = g_mnsh->export_list;
// 	while (it)
// 	{
// 		printf("declare -x %s", ((char **)it->data)[0]);
// 		if (((char **)it->data)[1])
// 			printf("=\"%s\"", ((char **)it->data)[1]);
// 		printf("\n");
// 		it = it->next;
// 	}
// }

// static int	export_var(char *av)
// {
// 	char	**kv;

// 	kv = my_string_split_by_first(av, "=");
// 	if (!kv)
// 		return (perror("export::"), -1);
// 	if (my_list_push_back(&g_mnsh->export_list, my_list_new_elem(kv, &my_list_data_clear)) == -1)
// 		return (perror("export::"), -1);
// 	export_sort();
// 	return (0);
// }

void	export(int ac, char **av, int status)
{
	(void)ac;
	(void)av;
	// int	i;

	// if (ac == 1)
	// {
	// 	print_export();
	// 	exit(EXIT_SUCCESS);
	// }
	// i = 0;
	// while (++i < ac)
	// 	if (export_var(av[i]) == -1)
	// 		exit(EXIT_FAILURE);
	// exit(EXIT_SUCCESS);
	if (status == YES_EXIT)
		exit(EXIT_SUCCESS);
	g_mnsh->exit_status = EXIT_SUCCESS;
}
