/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:44:58 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/18 15:15:31 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	tree_cleaner(t_ast **tree)
{
	if (!*tree)
		return ;
	tree_cleaner(&(*tree)->left);
	tree_cleaner(&(*tree)->right);
	my_list_clear(&((*tree)->value_expanded), free_string);
	free((*tree)->value);
	free(*tree);
	*tree = NULL;
}
