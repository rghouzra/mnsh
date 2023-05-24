/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:14:29 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/24 22:32:58 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_queue(t_queue *q)
{
	(q)->head = NULL;
	(q)->tail = NULL;
}

bool	enqueue(t_queue **q, char *value, t_tokentype type, t_list *next_word)
{
	t_queue	*new_n;

	new_n = ft_malloc(sizeof(t_queue));
	if (!new_n)
		exit(1);
	new_n->content = ft_strdup(value);
	new_n->next_word = next_word;
	new_n->type = type;
	new_n->next = NULL;
	new_n->head = NULL;
	new_n->tail = NULL;
	if (!*q)
		return (*q = new_n, (*q)->tail = new_n, (*q)->head = new_n, 1);
	if ((*q)->tail == NULL && (*q)->head == NULL)
	{
		(*q)->tail = new_n;
		(*q)->head = new_n;
	}
	(*q)->tail->next = new_n;
	(*q)->tail = new_n;
	return (true);
}

bool	dequeue(t_queue **q)
{
	t_queue	*tmp;

	if ((*q)->head == NULL)
		return (false);
	tmp = (*q)->head;
	(*q)->head = (*q)->head->next;
	if ((*q)->head == NULL)
		(*q)->tail = NULL;
	free(tmp);
	return (true);
}
