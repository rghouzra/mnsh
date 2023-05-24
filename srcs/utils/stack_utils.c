/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:59:34 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/24 22:32:58 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	peek(t_list *s)
{
	if (!s)
		return (-1);
	return (s->type);
}

bool	push(t_list **p, void *value, t_tokentype type, t_list *next_word)
{
	t_list	*n;

	n = ft_malloc(sizeof(t_list));
	if (!n)
		return (false);
	n->type = type;
	n->content = value;
	n->next_word = next_word;
	n->next = NULL;
	ft_lstadd_front(p, n);
	return (true);
}

t_poped	pop(t_list **p)
{
	t_list	*tmp;
	t_poped	x;

	x.type = -1;
	if (!*p)
		return (x);
	x.type = (*p)->type;
	x.content = (*p)->content;
	x.next_word = (*p)->next_word;
	tmp = *p;
	*p = (*p)->next;
	free(tmp);
	tmp = NULL;
	return (x);
}
