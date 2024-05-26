/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:31:48 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/14 15:18:00 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	insert_in_tree(t_ast **root, t_ast *new, int side)
{
	if (!*root)
	{
		*root = new;
		(*root)->side = side;
		return ;
	}
	if (side == LEFT)
	{
		insert_in_tree(&(*root)->left, new, LEFT);
	}
	if (side == RIGHT)
		insert_in_tree(&(*root)->right, new, RIGHT);
}

void	insert_subtree_in_tree(t_ast **tree, t_ast *subtree, int *indexref)
{
	static int	index;

	if(index == 0)
		indexref = &index;
	if (!subtree)
		return ;
	if (!*tree)
	{
		*tree = subtree;
		return ;
	}
	if ((*tree)->left == NULL && !(index % 2))
	{
		(*tree)->left = subtree;
		insert_subtree_in_tree(&(*tree)->left, subtree, indexref);
	}
	if ((*tree)->right == NULL && (index % 2))
	{
		(*tree)->right = subtree;
		insert_subtree_in_tree(&(*tree)->right, subtree, indexref);
	}
	index++;
}

static void	ast_constructor(t_ast **tree, t_list **prefix, int index)
{
	t_ast	*sub_tree;
	int *subtreeindexref;

	subtreeindexref = NULL;
	if (!*prefix)
		return ;
	if (index)
		*prefix = (*prefix)->next;
	if (!*prefix)
		return ;
	sub_tree = NULL;
	if (is_an_operator((*prefix)->type, 4) && ((*prefix)->type != redir_i
			|| (*prefix)->type != redir_o || (*prefix)->type != heredoc_i))
	{
		insert_in_tree(&sub_tree, ft_newastnode((*prefix)->type, \
			(*prefix)->content, (*prefix)->next_word), 0);
		ast_constructor(&sub_tree->right, prefix, RIGHT);
		ast_constructor(&sub_tree->left, prefix, LEFT);
	}
	else
		insert_in_tree(tree, ft_newastnode((*prefix)->type, (*prefix)->content, \
			(*prefix)->next_word), index);
	insert_subtree_in_tree(tree, sub_tree, subtreeindexref);
	if(subtreeindexref)
		*subtreeindexref = 0;
}

static t_ast	*generate_ast(t_queue **q)
{
	t_ast	*tree;
	t_list	*stack;
	t_list	*ptr;

	tree = NULL;
	stack = get_stack(q);
	if (stack)
	{
		ptr = stack;
		ast_constructor(&tree, &stack, 0);
		ft_lstclear(&ptr, del);
	}
	return (tree);
}

t_ast	*shunting_algorithm(t_list *token)
{
	t_queue	*q;
	t_list	*stack;
	t_poped	x;

	q = NULL;
	stack = NULL;
	while (token)
	{
		if (token->type == WORD || token->type == STRING \
			|| token->type == STR_SQ)
			enqueue(&q, token->content, token->type, token->next_word);
		else
			shunting_op_handler(token, &q, &stack);
		token = token->next;
	}
	if (!token)
	{
		while (stack)
		{
			x = pop(&stack);
			enqueue(&q, x.content, x.type, x.next_word);
		}
	}
	return (generate_ast(&q));
}
