/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:44:58 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/25 20:32:57 by rghouzra         ###   ########.fr       */
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
