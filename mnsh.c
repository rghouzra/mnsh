/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:41:31 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/18 10:04:44 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

t_minishell	*g_mnsh;

int	main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	g_mnsh = (t_minishell *)ft_malloc(sizeof(t_minishell));
	if (presh(env) == -1)
		exit(EXIT_FAILURE);
	signal_utils();
	read_input();
	my_list_clear(&(g_mnsh->env_list), &my_list_data_clear);
	my_list_clear(&(g_mnsh->export_list), &my_list_data_clear);
	my_strings_free(&(g_mnsh->paths_list));
	free(g_mnsh);
	return (EXIT_SUCCESS);
}
