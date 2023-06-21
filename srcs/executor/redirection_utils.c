/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 04:37:03 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/21 04:48:54 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_redir_optimizer(t_ast *tree)
{
	if (tree->left && tree->right)
	{
		if (tree->left->type == WORD && tree->right->type == WORD)
			return (1);
	}
	if (tree->left)
	{
		if (tree->left->type == redir_o || tree->left->type == append_o)
			return (2);
		if (tree->left->type == redir_i)
			return (3);
		if (tree->left->type == heredoc_i)
			return (4);
	}
	return (0);
}

t_my_list	*get_expanded_values(t_ast *tree)
{
	expand_term(tree->right);
	return (tree->right->value_expanded);
}

char	**check_return_gev(t_ast *tree)
{
	char		**leafs;
	t_my_list	*list;

	list = get_expanded_values(tree);
	if (list == NULL)
		return ((g_mnsh->exit_status = 1), NULL);
	leafs = convert_to_table(list);
	if (leafs == NULL)
		return (g_mnsh->exit_status = 1, NULL);
	if (my_strings_count(leafs) > 1)
		return (g_mnsh->exit_status = 1, \
			perror("ambiguous redirect"), ft_free(leafs), NULL);
	return (leafs);
}
