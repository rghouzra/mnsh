#include "header.h"

t_ast	*newAstNode(t_tokentype type, void *value, t_list *next_word)
{
	t_ast	*node;

	node = (t_ast *)ft_malloc(sizeof(t_ast));
	node->type = type;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	node->next_word = next_word;
	return (node);
}

void	shunting_op_handler(t_list *token, t_queue **queue, t_list **stack)
{
	t_poped	x;

	if (token)
	{
		if (!*stack && (is_an_operator(token->type, 4) || token->type == opar))
			push(stack, token->content, token->type, token->next_word);
		else if (*stack)
		{
			if ((!is_an_operator((*stack)->type, 4)
					&& is_an_operator(token->type, 4)) || token->type == opar)
				push(stack, token->content, token->type, token->next_word);
			else if (is_an_operator(token->type, 4)
					&& is_an_operator((*stack)->type, 4))
			{
				while(*stack && get_token_priority(token) >= get_token_priority(*stack))
				{
					x = pop(stack);
					enqueue(queue, x.content, x.type, x.next_word);
				}
				push(stack, token->content, token->type, token->next_word);
			}
			else if (token->type == cpar)
			{
				while (*stack && (*stack)->type != opar)
				{
					x = pop(stack);
					if (x.type != opar)
						enqueue(queue, x.content, x.type, x.next_word);
				}
				pop(stack);
			}
		}
	}
}


bool	push_back(t_list **p, void *value, t_tokentype type)
{
	t_list	*n;

	n = ft_malloc(sizeof(t_list));
	if (!n)
		return (false);
	n->type = type;
	n->content = value;
	n->next = NULL;
	ft_lstadd_back(p, n);
	return (true);
}

t_list	*get_stack(t_queue **queue)
{
	t_list *stack;
	t_queue *ptr;
	t_queue *tmp;

    if (!*queue)
        return NULL;
	stack = NULL;
	ptr = (*queue)->head;
	while (ptr)
	{
		tmp = ptr;
		push(&stack, ptr->content, ptr->type, ptr->next_word);
		ptr = ptr->next;
		free(tmp);
	}
	return (stack);
}
