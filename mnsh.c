/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:41:31 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/27 05:34:28 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mnsh.h"

void test()
{
	// export_sort();
	// t_my_list *it = g_mnsh->export_list;
	// while (it)
	// {
	// 	printf("%s=%s\n", ((char **)it->data)[0], ((char **)it->data)[1]);
	// 	it = it->next;
	// }
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	g_mnsh = (t_minishell *)ft_malloc(sizeof(t_minishell));
	rl_catch_signals = 0;
	if (presh(env) == -1)
		exit(EXIT_FAILURE);
	test();
	// test();
	signal_utils();
	read_input();
	my_list_clear(&(g_mnsh->env_list));
	my_list_clear(&(g_mnsh->export_list));
	my_strings_free(&(g_mnsh->paths_list));
	free(g_mnsh);
	return (EXIT_SUCCESS);
}
