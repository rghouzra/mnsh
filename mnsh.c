/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:57:44 by rghouzra          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/26 15:38:21 by yrhiba           ###   ########.fr       */
=======
/*   Updated: 2023/05/25 21:14:32 by rghouzra         ###   ########.fr       */
>>>>>>> 5287e57c43f08ff51e843144d72fad3555fec543
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
<<<<<<< HEAD
	if (presh(env) == -1)
		exit(EXIT_FAILURE);
	test();
=======
	g_mnsh->env_list = 0;
	g_mnsh->paths_list = 0;
	g_mnsh->exit_status = 0;
	// presh(env);
>>>>>>> 5287e57c43f08ff51e843144d72fad3555fec543
	read_input();
	my_list_clear(&(g_mnsh->env_list));
	my_list_clear(&(g_mnsh->export_list));
	my_strings_free(&(g_mnsh->paths_list));
	free(g_mnsh);
	return (EXIT_SUCCESS);
}
