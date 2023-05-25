/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:57:44 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/25 18:46:44 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void	read_input(char **env)
{
	char	*s;
	t_list	*token;
	t_ast	*tree;

	while (1)
	{
		s = readline("sh-1.0$ ");
		if (!s)
		{
			fprintf(stderr, "exit");
			exit(1);
		}
		token = tokenizer(s);
		evaluate_expression(token);
		if(lexer(token))
		{
			add_history(s);
			tree = shunting_algorithm(token);
			// if (tree)
				// eval_tree(tree, 0, (t_io){0, 1, -2, -2, 0});
			tree_cleaner(&tree);
		}
		ft_tokencleaner(&token);
		free(s);
	}
	clear_history();
}
