/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:57:44 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/26 15:38:21 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void test()
{
	int	i = 0;
	while (g_mnsh->paths_list[i])
		printf("%s\n", g_mnsh->paths_list[i++]);
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	g_mnsh = (t_minishell *)ft_malloc(sizeof(t_minishell));
	if (presh(env) == -1)
		exit(EXIT_FAILURE);
	test();
	read_input();
	my_list_clear(&(g_mnsh->env_list));
	my_list_clear(&(g_mnsh->export_list));
	my_strings_free(&(g_mnsh->paths_list));
	free(g_mnsh);
	return (EXIT_SUCCESS);
}
