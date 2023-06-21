/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:12:16 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/21 13:06:40 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	updat_pwd(char **old_pwd, int mode)
{
	char	*pwd;
	char	**args;

	args = malloc(sizeof(char *) * 3);
	if (!args)
		return (exit_status(EXIT_FAILURE, mode), -1);
	args[2] = NULL;
	pwd = getpwd();
	if (!pwd)
		return (perror("mnsh::cd"), exit_status(EXIT_FAILURE, mode), -1);
	if (my_string_update(&pwd, my_string_join("PWD=", pwd)) == -1)
		return (perror("mnsh::cd"), exit_status(EXIT_FAILURE, mode), -1);
	args[1] = pwd;
	export(2, args, NO_EXIT);
	if (old_pwd)
	{
		if (my_string_update(old_pwd, \
			my_string_join("OLDPWD=", *old_pwd)) == -1)
			return (perror("mnsh::cd"), \
			exit_status(EXIT_FAILURE, mode), -1);
		args[1] = *old_pwd;
		export(2, args, NO_EXIT);
		free(*old_pwd);
	}
	return (free(args), free(pwd), 0);
}

static int	change_dir(char *dir)
{
	char	*new;

	new = (char *)0;
	if (!dir)
	{
		if (!env_var_exist("HOME"))
			return (perror("ENV HOME NOT SET"), -1);
		new = my_string_dup(envgetvalue("HOME"));
	}
	else
		new = my_string_dup(dir);
	if (!new)
		return (perror("mnsh::cd::"), -1);
	if (my_string_append_char(&new, '/') == -1)
		return (free(new), perror("mnsh::cd"), -1);
	if (chdir(new) == -1)
		return (free(new), perror("mnsh::cd::"), -1);
	return (free(new), 0);
}

static int	gohome(int mode)
{
	char	*new;

	new = my_string_dup(envgetvalue("HOME"));
	if (!new)
		exit_status(EXIT_FAILURE, mode);
	if (chdir(new) == -1)
		return (free(new), perror("mnsh::cd::"), -1);
	return (free(new), updat_pwd(NULL, mode), 0);
}

int	cd(int ac, char **av, int mode)
{
	char	*old_pwd;

	old_pwd = getpwd();
	if (!old_pwd)
		return (gohome(mode), perror("mnsh::cd"), \
			exit_status(EXIT_FAILURE, mode), 1);
	if (ac > 1)
	{
		if (change_dir(av[1]) == -1)
			return (exit_status(EXIT_FAILURE, mode));
	}
	else if (change_dir(NULL) == -1)
		return (exit_status(EXIT_FAILURE, mode));
	return (updat_pwd(&old_pwd, mode), exit_status(EXIT_SUCCESS, mode));
}
