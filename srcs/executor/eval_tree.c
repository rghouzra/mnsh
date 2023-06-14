/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:34:18 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/13 16:16:05 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void	execute_with_fork(char **cmnds, t_io x)
{
	pid_t	pid;

	if(ifbuiltinbreak(cmnds, NO_EXIT) == EXIT_SUCCESS)
		return ;
	pid = ft_fork();
	if (!pid)
	{
		if (x.be_dupped == -1)
			show_error(strerror(errno), 1);
		if (!*(cmnds + x.increment))
		{
			waitpid(pid, &(g_mnsh->exit_status), 0);
			return ;
		}
		if (x.stream != -2)
			dup2(x.be_dupped, x.stream);
		execute(cmnds + x.increment);
	}
	else
		waitpid(pid, &(g_mnsh->exit_status), 0);
	my_strings_free(&cmnds);
}

void	dup_close(int *fd, int new_fd, int index)
{
	dup2(fd[index], new_fd);
	close(fd[1]);
	close(fd[0]);
}

void	pipeline(t_ast *tree, t_io x)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (!tree)
		return ;
	ft_pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup_close(fd, x.output, 1);
		eval_tree(tree->left, 1, x);
		exit(0);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup_close(fd, x.input, 0);
		eval_tree(tree->right, 1, x);
		exit(0);
	}
	close(fd[1]);
	close(fd[0]);
	waitpid(pid1, &(g_mnsh->exit_status), 0);
	waitpid(pid2, &(g_mnsh->exit_status), 0);
}

void	get_virual_operands(char *operands, t_openpar x, int is_running)
{
	char	**leafs;
	int		fd;
	char	*tmp;

	leafs = ft_split(operands, ' ');
	if (!leafs)
		return ;
	tmp = leafs[0];
	fd = open(tmp, x.flags, x.permissions);
	if (is_running)
	{
		if (fd == -1)
			show_error(strerror(errno), 126);
		dup2(fd, x.stream);
		execute(leafs + 1);
	}
	else
		execute_with_fork(leafs, (t_io){-2, -2, fd, x.stream, 1});
	close(fd);
}

void	eval_logical_op(t_ast *tree, t_io x)
{
	if (tree->type == AND_CMD_CHAIN)
	{
		eval_tree(tree->left, 0, x);
		if (!g_mnsh->exit_status)
			eval_tree(tree->right, 0, x);
	}
	if (tree->type == OR_CMD_CHAIN)
	{
		eval_tree(tree->left, 0, x);
		if (g_mnsh->exit_status)
			eval_tree(tree->right, 0, x);
	}
}

void	eval_tree(t_ast *tree, int is_child, t_io x)
{
	if (!tree)
		return ;
	if (tree->type == redir_o)
		handle_rediro(tree, x, is_child);
	if (tree->type == redir_i)
		handle_rediri(tree, x, is_child);
	if (tree->type == append_o)
		handle_append(tree, x, is_child);
	if (tree->type == PIPE)
		pipeline(tree, x);
	if (tree->type == WORD)
	{
		expand_term(tree);
	
		// TEST
		// printf("head->%s\n", tree->value);
		// t_list *n = tree->next_word;
		// while(n)
		// {
		// 	printf("%s\n", n->content);
		// 	n = n->next_word;
		// }
		// TEST

		// if (is_child)
		// 	execute(ft_split(tree->value, ' '));
		// else
		// 	execute_with_fork(ft_split(tree->value, ' '), x);
	}
	else
		eval_logical_op(tree, x);
}
