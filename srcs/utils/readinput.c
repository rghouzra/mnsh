/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:57:44 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/17 17:49:23 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static void	print_dot(t_ast *node, int i, int *count, FILE *p)
{
	int	node_id;

	if (node == 0x0)
		return ;
	node_id = ++(*count);
	fprintf(p, "  node%d [label=\"%s\"];\n", node_id, node->value);
	if (i != -666)
		fprintf(p, "  node%d -> node%d;\n", i, node_id);
	print_dot(node->left, node_id, count, p);
	print_dot(node->right, node_id, count, p);
}

void	print_tree_dot(t_ast *root, char *s)
{
	int		count;
	FILE	*p;

	p = fopen("treegraph.dot", "w");
	fprintf(p, "/*\n%s\n*/\n", s);
	fprintf(p, "digraph {\n");
	count = 0;
	print_dot(root, -666, &count, p);
	fprintf(p, "}\n");
	fflush(p);
}

void	print_tk(t_list *token)
{
	t_list	*tmp;
	while (token)
	{
		printf("[%s]->:\t%d\n", token->content, token->type);
		tmp = token->next_word;
		if(tmp)
		{
			while(tmp)
			{
				printf("next_word: %s\n",tmp->content);
				tmp = tmp->next_word;	
			}
		}
		token = token->next;
	}
	putchar('\n');
}

void	read_input(void)
{
	char	*s;
	t_list	*token;
	t_ast	*tree;

	while (1)
	{
		signal_utils();
		s = readline("sh-1.0$ ");
		if (!s)
		{
			ft_putendl_fd("exit", STDERR_FILENO);
			exit(1);
		}
		token = tokenizer(s);
		if (lexer(token))
		{
			add_history(s);
			tree = shunting_algorithm(token);
			print_tree_dot(tree, s);
			if (tree)
				eval_tree(tree, 0, (t_io){0,0, 0, 1, -2, -2, 0});
			tree_cleaner(&tree);
		}
		ft_tokencleaner(&token);
		free(s);
	}
	clear_history();
}
