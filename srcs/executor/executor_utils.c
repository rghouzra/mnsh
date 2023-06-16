/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:43:03 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/16 15:59:39 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

char	*execute(char **cmnds)
{
	char	*cmd;
	char	**ev;

	if(!*cmnds)
		exit(0);
	ifbuiltinbreak(cmnds, YES_EXIT);
	cmd = getcmdfullpath(*cmnds);
	ev = contrui_env();
	execve(cmd, cmnds, ev);
	ft_putstr_fd(cmnds[0], 2);
	ft_putstr_fd(": Command not found\n", 2);
	return (my_strings_free(&cmnds), my_strings_free(&ev), free(cmd), exit(127),
		NULL);
}

int	check_access(char *path, int which)
{
	if (which == 0)
	{
		if (!(access(path, R_OK)))
			return (open(path, O_RDONLY));
	}
	else if (which == 1)
	{
		if (!(access(path, F_OK)))
			return (1);
	}
	else if (which == 3)
	{
		if (!(access(path, X_OK)))
			return (1);
	}
	return (-1);
}

void	get_virual_operands(char *operands, t_openpar x, int is_running,
		t_ast *tree)
{
	char	**leafs;
	int		fd;
	char	*tmp;

	(void)operands;
	leafs = contrui_cmnds(tree->right);
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
