/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:17:53 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/25 20:32:16 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_redir_optimizer(t_ast *tree)
{
	if(tree->left &&  tree->right)
		if(tree->left->type == WORD && tree->right->type == WORD)
			return 1;
	return (0);
}


void handle_rediro(t_ast *tree, t_io x, int is_child)
{
	int fd;

	fd = -1;
	if (ft_redir_optimizer(tree))
	{
		fd = open(tree->right->value, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if (fd == -1)
			show_error(strerror(errno), 126);
		if (is_child)
			dup2(fd, x.output);
		else
		{
			x.be_dupped = fd;
			x.stream = x.output;
		}
		if(ft_redir_optimizer(tree) == 1)
			eval_tree(tree->left, is_child, x);
	}
	else
		get_virual_operands(tree->right->value, (t_openpar){O_CREAT|O_WRONLY|O_TRUNC, 0777, x.output}\
		, is_child);
	close(fd);
}

void handle_rediri(t_ast *tree, t_io x, int is_child)
{
    int fd;

	fd = -1;
    if(ft_redir_optimizer(tree) == 1)
	{
		fd = open(tree->right->value, O_RDONLY);
		if (fd == -1)
			show_error(strerror(errno), 126);
		if (is_child)
			dup2(fd, x.input);
		else
		{
			x.be_dupped = fd;
			x.stream = x.input;
		}
		eval_tree(tree->left, is_child, x);
	}
	else
		get_virual_operands(tree->right->value, (t_openpar){O_RDONLY, 0, x.input}, is_child);
	close(fd);
}

void handle_append(t_ast *tree, t_io x, int is_child)
{
    int fd;

	fd = -1;
	if (ft_redir_optimizer(tree))
	{
		if (access(tree->right->value, F_OK))
			fd = open(tree->right->value,O_CREAT | O_WRONLY , 0777);
		else
			fd = open(tree->right->value, O_WRONLY|O_APPEND);
		if (fd == -1)
			show_error(strerror(errno), 126);
		if (is_child)
			dup2(fd, x.output);
		else
		{
			x.be_dupped = fd;
			x.stream = x.output;
		}
		if(ft_redir_optimizer(tree) == 1)
			eval_tree(tree->left, is_child, x);
	}
	else
		get_virual_operands(tree->right->value, (t_openpar){O_CREAT|O_WRONLY|O_TRUNC, 0777, x.output}\
		, is_child);
	close(fd);
}
