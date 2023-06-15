/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:27:27 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/15 18:54:00 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void	handle_heredoc(t_ast *tree, t_io x, int is_child)
{
	int	fd;

	fd = -1;
	if (ft_redir_optimizer(tree) == 1)
	{
		fd = open(tree->right->value, O_RDONLY);
		printf("value->%s\n", tree->right->value);
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
		get_virual_operands(tree->right->value, (t_openpar){O_RDONLY, 0,
				x.input}, is_child, tree);
	close(fd);
}