/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:44:58 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/25 18:45:01 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	tree_cleaner(t_ast **tree)
{
	if (!*tree)
		return ;
	tree_cleaner(&(*tree)->left);
	tree_cleaner(&(*tree)->right);
	free((*tree)->value);
	free(*tree);
}
