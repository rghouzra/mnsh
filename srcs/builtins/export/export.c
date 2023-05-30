/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:08:01 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/30 23:34:19 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static void	print_export(void)
{
	t_my_list	*it;

	it = g_mnsh->export_list;
	while (it)
	{
		printf("declare -x %s", ((char **)it->data)[0]);
		if (((char **)it->data)[1])
			printf("=\"%s\"", ((char **)it->data)[1]);
		printf("\n");
		it = it->next;
	}
}

static int	export_var(char *av)
{
	char	**kv;

	kv = my_string_split_by_first(av, "=");
	if (!kv)
		return (-1);
	printf("%s -> %s\n", kv[0], kv[1]);
	return (0);
}

void	export(int ac, char **av)
{
	int	i;

	if (ac == 1)
	{
		print_export();
		exit(EXIT_SUCCESS);
	}
	i = 0;
	while (++i < ac)
		if (export_var(av[i]) == -1)
			exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
