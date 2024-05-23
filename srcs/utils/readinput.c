/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:57:44 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/21 22:05:44 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static void	print_dot(t_ast *node, int i, int *count, FILE *p)
{
	int	node_id;

	if (node == 0x0)
		return ;
	node_id = ++(*count);
	fprintf(p, "  node%d [label=\"%s\"];\n", node_id, (char *)node->value);
	if (i != -1)
		fprintf(p, "  node%d -> node%d;\n", i, node_id);
	print_dot(node->left, node_id, count, p);
	print_dot(node->right, node_id, count, p);
}

void	print_tree_dot(t_ast *root, char *s, FILE *p)
{
	int		count;

	fprintf(p, "/*\n%s\n*/\n", s);
	fprintf(p, "digraph {\n");
	count = 0;
	print_dot(root, -1, &count, p);
	fprintf(p, "}\n");
	fflush(p);
}

void	read_input(void)
{
	char	*in_line;
	t_list	*token;
	t_ast	*tree;
	FILE	*p;

	p = fopen("treegraph.dot", "w");
	if (!p){
		perror(strerror(errno));
		exit(1);
	}
	while (1)
	{
		signal_utils();
		in_line = readline("sh-1.0$ ");
		if (!in_line)
		{
			ft_putendl_fd("exit", STDERR_FILENO);
			fclose(p);
			exit(0);
		}
		token = tokenizer(in_line);
		if (lexer(token))
		{
			tree = shunting_algorithm(token);
			if (tree){
				print_tree_dot(tree, in_line, p);
				eval_tree(tree, 0, (t_io){0, 0, 0, 1, -2, -2, 0});
			}
			tree_cleaner(&tree);
		}
		ft_tokencleaner(&token);
		free(in_line);
	}
	clear_history();
	fclose(p);
}

