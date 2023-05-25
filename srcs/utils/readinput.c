/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:57:44 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/25 17:45:48 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void	read_input(char **env)
{
	char	*s;
	t_list	*token;
	t_ast	*tree;

	// signal(SIGINT, sigint_handler);
	while (1)
	{
		init_global(env, &minishell);
		s = readline(BLUE "sh-1.0$ " RESET);
		if (!s)
		{
			fprintf(stderr, "exit");
			exit(1);
		}
		token = tokenizer(s);
		evaluate_expression(token);
		# if 0
		print_token(token);
		#endif
		if(lexer(token))
		{
			add_history(s);
			tree = shunting_algorithm(token);
			if (tree)
			#if 1
				print_tree_dot(tree, s);
				eval_tree(tree, get_path(minishell.environ), 0, (t_io){0, 1, -2, -2, 0});
			#endif
			tree_cleaner(&tree);
		}
		env_cleaner(&minishell.environ, del);
		ft_tokencleaner(&token);
		free(s);
	}
	clear_history();
}
