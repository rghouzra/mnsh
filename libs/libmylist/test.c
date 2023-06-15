/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:54:24 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/14 18:06:27 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"
#include <stdio.h>
#include <stdlib.h>

/*
	content  void * -> struct
	next
*/

void	free_content(void **content)
{
	free(*content);
}

int	*int_dup(int m)
{
	int *n =  malloc(sizeof(int));
	*n = m;
	return (n);
}

int main()
{
	t_my_list *list;

	my_list_init(&list);

	for (int i = 1; i <= 10; i++)
	{
		if (my_list_push_back(&list, my_list_new_elem(int_dup(i), free_content)) == -1)
			exit(EXIT_FAILURE);
	}
	t_my_list *zb = list;
	while(list)
	{
		printf("\n%d\n", *(int *)list->data);
		list = list->next;
	}
	my_list_clear(&zb, free_content);
	while(1);
}