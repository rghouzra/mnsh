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

void	insert_subtree_in_tree(t_ast **tree, t_ast *subtree)
{
	static int	index;

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
		insert_subtree_in_tree(&(*tree)->left, subtree);
	}
	if ((*tree)->right == NULL && (index % 2))
	{
		(*tree)->right = subtree;
		insert_subtree_in_tree(&(*tree)->right, subtree);
	}
	index++;
}

static void	ast_constructor(t_ast **tree, t_list **prefix, int index)
{
	t_ast	*sub_tree;

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
		insert_in_tree(&sub_tree, newAstNode((*prefix)->type,
					(*prefix)->content, (*prefix)->next_word), 0);
		ast_constructor(&sub_tree->right, prefix, RIGHT);
		ast_constructor(&sub_tree->left, prefix, LEFT);
	}
	else
		insert_in_tree(tree, newAstNode((*prefix)->type, (*prefix)->content,
					(*prefix)->next_word), index);
	insert_subtree_in_tree(tree, sub_tree);
}

void	print_ast(t_ast *tree, int side)
{
	if (tree == NULL)
		return ;
	print_ast(tree->left, LEFT);
	print_ast(tree->right, RIGHT);
	printf("in tree: %s\tside->%d\n",tree->value, side);
}

void	print_stack(t_list *stack)
{
	if (stack)
		while (stack)
		{
			printf("%s ", stack->content);
			stack = stack->next;
		}
	printf("\n");
}

static t_ast	*generate_ast(t_queue **q)
{
	t_ast	*tree;
	t_list	*stack;
	t_list	*ptr;

	tree = NULL;
	stack = get_stack(q);
	// print_stack(stack);
    if(stack)
    {
	    ptr = stack;
	    ast_constructor(&tree, &stack, 0);
       //  print_ast(tree, 0);
	    ft_lstclear(&ptr, del);
    }
	return (tree);
}

t_ast	*shunting_algorithm(t_list *token)
{
	t_queue *q;
	t_list *stack;
	t_poped x;
	t_ast *tree;

	if (!token)
		return (NULL);
	q = NULL;
	stack = NULL;
	while (token)
	{
		if (token->type == WORD || token->type == STRING
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
	tree = generate_ast(&q);
	return (tree);
}