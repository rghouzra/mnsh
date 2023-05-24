/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:34:18 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/24 22:32:04 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define EXEC 111
# define LEFT 666
# define RIGHT 999
# define PARENT 0

void execute_with_fork(char **cmnds, char *env, t_io x)
{
	pid_t	pid;

	pid = ft_fork();
	if(!pid)
	{
		if (x.be_dupped == -1)
			show_error(strerror(errno), 1);
		if(!*(cmnds + x.increment))
		{
			waitpid(pid, &minishell.exit_status, 0);
			return ;
		}
		if (x.stream != -2)
			dup2(x.be_dupped, x.stream);
		execute(env, cmnds + x.increment);
	}
	else
		waitpid(pid, &minishell.exit_status, 0);
	ft_free(cmnds);
}

void pipeline(t_ast *tree, char *env, t_io x)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (!tree)
		return ;
		ft_pipe(fd);
		pid1 = fork();
		if(pid1 == 0)
		{
			dup2(fd[1], x.output);
			close(fd[1]);
			close(fd[0]);
			eval_tree(tree->left, env, 1, x);
			exit(0);
		}
		pid2 = fork();
		if(pid2 == 0)
		{
			dup2(fd[0], x.input);
			close(fd[0]);
			close(fd[1]);
			eval_tree(tree->right, env, 1, x);
			exit(0);
		}
		close(fd[1]);
		close(fd[0]);
		waitpid(pid1, &minishell.exit_status, 0);
		waitpid(pid2, &minishell.exit_status, 0);
}
// !TODO: fix broken pipe
// TODO: free leafs in execute frame
void get_virual_operands(char *operands, t_openpar x, int is_running, char *env)
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
		execute(env, leafs + 1);
	}
	else
		execute_with_fork(leafs, env, (t_io){-2, -2, fd,  x.stream, 1});
	close(fd);
}

void eval_logical_op(t_ast *tree, char *env, int is_child, t_io x)
{
	if (tree->type == AND_CMD_CHAIN)
	{
		eval_tree(tree->left, env, is_child, x);
		if (!minishell.exit_status)
			eval_tree(tree->right, env, is_child, x);
	}
	if (tree->type == OR_CMD_CHAIN)
	{
		eval_tree(tree->left, env, is_child, x);
		if (minishell.exit_status)
			eval_tree(tree->right, env, is_child, x);
	}
}
void	eval_tree(t_ast *tree, char *env, int is_child, t_io x)
{
	if (!tree)
		return ;
    if (tree->type == redir_o)
		handle_rediro(tree, x, is_child, env);
    if (tree->type == redir_i)
		handle_rediri(tree, x, is_child, env);
	if(tree->type == append_o)
		handle_append(tree, x, is_child, env);
	if (tree->type == PIPE)
		pipeline(tree, env, x);
	if (tree->type == WORD)
	{
		if (is_child)
			execute(env, ft_split(tree->value, ' '));
		else
			execute_with_fork(ft_split(tree->value, ' '), env, x);
	}
	else
		eval_logical_op(tree, env, is_child, x);
}

