/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:43:03 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/24 22:32:14 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_cmd(char *cmnd, char *env)
{
	char	**paths;
	char	*prefixed_cmd;
	char	*full_cmnd;
	char	**ptr;

	if (!cmnd || !env)
		return (NULL);
	ptr = NULL;
	prefixed_cmd = NULL;
	if (ft_strchr(cmnd, '/') && check_access(cmnd, 3))
		return (cmnd);
	prefixed_cmd = ft_strjoin("/", cmnd, 0);
	paths = ft_split(env, ':');
	ptr = paths;
	while (*paths)
	{
		cmnd = ft_strjoin(*paths, prefixed_cmd, 0);
		if (check_access(cmnd, 3) == 1)
			return (free(prefixed_cmd), ft_free(ptr), cmnd);
		paths++;
		free(cmnd);
	}
	free(prefixed_cmd);
	ft_free(ptr);
	return (perror("command not found"), NULL);
}

char	*execute(char *env, char **cmnds)
{
	char	*cmd;

	if (!env || !cmnds || !*cmnds)
		return (NULL);
	cmd = get_cmd(*cmnds, env);
	if (!cmnds)
		show_error(strerror(errno), 1);
	execve(cmd, cmnds, NULL);
	show_error(strerror(errno), 127);
	return (NULL);
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
