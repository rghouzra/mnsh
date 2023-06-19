/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:40:09 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/17 18:35:16 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	pwd(int ac, char **av, int mode)
{
	char	*dir;

	(void)ac;
	(void)av;
	dir = (char *)malloc(sizeof(char) * MNSH_PATH_MAX);
	if (!dir)
	{
		perror("pwd::malloc failed::");
		exit_status(EXIT_FAILURE, mode);
	}
	if (!getcwd(dir, MNSH_PATH_MAX * sizeof(char)))
	{
		perror("pwd::getcwd failed::");
		free(dir);
		exit_status(EXIT_FAILURE, mode);
	}
	printf("%s\n", dir);
	free(dir);
	return (exit_status(EXIT_SUCCESS, mode));
}
