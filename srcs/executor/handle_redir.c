/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:17:53 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/20 16:21:49 by rghouzra         ###   ########.fr       */
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
	return tree->right->value_expanded;
}

void	handle_rediro(t_ast *tree, t_io x, int is_child)
{
	int	fd;

	fd = -1;
	if (ft_redir_optimizer(tree))
	{
		if(get_expanded_values(tree) == NULL)
			return ;
		fd = ft_open(tree->right->value, O_CREAT | O_WRONLY | O_TRUNC, 0644, &g_mnsh->exit_status);
		if (is_child)
			dup2(fd, x.output);
		else if (!x.rediro_prev)
		{
			x.rediro_prev = 1;
			x.be_dupped = fd;
			x.stream = x.output;
		}
		eval_tree(tree->left, is_child, x);
	}
	else
		get_virual_operands(tree->right->value,
			(t_openpar){O_CREAT | O_WRONLY | O_TRUNC, 0777, x.output}, \
			is_child, tree);
	close(fd);
}

void	handle_rediri(t_ast *tree, t_io x, int is_child)
{
	int	fd;

	fd = -1;
	if (ft_redir_optimizer(tree) == 1)
	{
		if(get_expanded_values(tree) == NULL)
				return ;
		fd = ft_open(tree->right->value, O_RDONLY, 0, &g_mnsh->exit_status);
		if (fd == -1)
			show_error(strerror(errno), 126);
		if (is_child)
			dup2(fd, x.input);
		else if (!x.rediri_prev)
		{
			x.rediri_prev = 1;
			x.be_dupped = fd;
			x.stream = x.input;
		}
		eval_tree(tree->left, is_child, x);
	}
	else
		get_virual_operands(tree->right->value, (t_openpar){O_RDONLY, 0, \
			x.input}, is_child, tree);
	close(fd);
}

void	handle_append(t_ast *tree, t_io x, int is_child)
{
	int	fd;

	fd = -1;
	if (ft_redir_optimizer(tree))
	{
		if (get_expanded_values(tree) == NULL)
				return ;
		if (access(tree->right->value, F_OK))
			fd = ft_open(tree->right->value, O_CREAT | O_WRONLY, 0777, &g_mnsh->exit_status);
		else
			fd = ft_open(tree->right->value, O_WRONLY | O_APPEND, 0, &g_mnsh->exit_status);
		if (is_child)
			dup2(fd, x.output);
		else if (!x.rediro_prev)
		{
			x.be_dupped = fd;
			x.stream = x.output;
			x.rediro_prev = 1;
		}
		eval_tree(tree->left, is_child, x);
	}
	else
		get_virual_operands(tree->right->value, \
			(t_openpar){O_CREAT | O_WRONLY | O_TRUNC, 0777, x.output},
			is_child, tree);
	close(fd);
}

void	handle_heredoc(t_ast *tree, t_io x, int is_child)
{
	int	fd;

	fd = -1;
	if (ft_redir_optimizer(tree))
	{
		if (get_expanded_values(tree) == NULL)
				return ;
		fd = ft_open(tree->right->value, O_RDONLY, 0, &g_mnsh->exit_status);
		if (is_child)
			dup2(fd, x.input);
		else if (!x.rediri_prev)
		{
			x.rediri_prev = 1;
			x.be_dupped = fd;
			x.stream = x.input;
		}
		eval_tree(tree->left, is_child, x);
	}
	else
		get_virual_operands(tree->right->value, (t_openpar){O_RDONLY, 0,
			x.input}, is_child, tree);
	close(fd);
	unlink(*contrui_cmnds(tree->right));
}
