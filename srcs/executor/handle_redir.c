/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:17:53 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/21 04:58:33 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dup_stream(t_io *x, int fd, int option)
{
	if (option)
	{
		x->rediro_prev = 1;
		x->be_dupped = fd;
		x->stream = x->output;
	}
	else
	{
		x->rediri_prev = 1;
		x->stream = x->input;
		x->be_dupped = fd;
	}
}

void	handle_rediro(t_ast *tree, t_io x, int is_child)
{
	int		fd;
	char	**leafs;

	if (ft_redir_optimizer(tree))
	{
		leafs = check_return_gev(tree);
		if (leafs == NULL)
			return ;
		fd = ft_open(leafs[0], O_CREAT | O_WRONLY | O_TRUNC, 0644, \
			&g_mnsh->exit_status);
		if (is_child)
			dup2(fd, x.output);
		else if (!x.rediro_prev)
			dup_stream(&x, fd, 1);
		eval_tree(tree->left, is_child, x);
		close(fd);
		ft_free(leafs);
	}
	else
		get_virual_operands(tree->right->value, \
			(t_openpar){O_CREAT | O_WRONLY | O_TRUNC, 0777, x.output}, \
			is_child, tree);
}

void	handle_rediri(t_ast *tree, t_io x, int is_child)
{
	int		fd;
	char	**leafs;

	if (ft_redir_optimizer(tree) == 1)
	{
		leafs = check_return_gev(tree);
		if (leafs == NULL)
			return ;
		fd = ft_open(leafs[0], O_RDONLY, 0, &g_mnsh->exit_status);
		if (fd == -1)
			show_error(strerror(errno), 126);
		if (is_child)
			dup2(fd, x.input);
		else if (!x.rediri_prev)
			dup_stream(&x, fd, 0);
		eval_tree(tree->left, is_child, x);
		close(fd);
		ft_free(leafs);
	}
	else
		get_virual_operands(tree->right->value, (t_openpar){O_RDONLY, 0, \
			x.input}, is_child, tree);
}

void	handle_append(t_ast *tree, t_io x, int is_child)
{
	int		fd;
	char	**leafs;

	if (ft_redir_optimizer(tree))
	{
		leafs = check_return_gev(tree);
		if (leafs == NULL)
			return ;
		if (access(leafs[0], F_OK))
			fd = ft_open(leafs[0], 512 | 1, 0777, &g_mnsh->exit_status);
		else
			fd = ft_open(leafs[0], 1 | 8, 0, &g_mnsh->exit_status);
		if (is_child)
			dup2(fd, x.output);
		else if (!x.rediro_prev)
			dup_stream(&x, fd, 1);
		eval_tree(tree->left, is_child, x);
		close(fd);
		ft_free(leafs);
	}
	else
		get_virual_operands(tree->right->value, \
			(t_openpar){O_CREAT | O_WRONLY | O_TRUNC, 0777, x.output},
			is_child, tree);
}

void	handle_heredoc(t_ast *tree, t_io x, int is_child)
{
	int		fd;
	char	**cmnds;

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
		close(fd);
	}
	else
		get_virual_operands(tree->right->value, (t_openpar){O_RDONLY, 0,
			x.input}, is_child, tree);
	cmnds = contrui_cmnds(tree->right);
	unlink(*cmnds);
	ft_free(cmnds);
}
