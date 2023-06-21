/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:46:31 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/21 21:46:02 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	addarg(t_echo *data, char *s)
{
	char	*to_append;

	if (!data->buff)
	{
		if (my_string_append(&data->buff, s) == -1)
			return (-1);
	}
	else
	{
		to_append = my_string_join(" ", s);
		if (!to_append)
			return (-1);
		if (my_string_append(&data->buff, to_append) == -1)
			return (free(to_append), -1);
		free(to_append);
	}
	return (0);
}

static int	scan_synp(t_echo *data, char *s)
{
	if (data->flag)
		return (1);
	if (my_string_compare(s, "-n") == LS_EQUAL)
		return (data->n = 1, 0);
	return (1);
}

static int	addbn(t_echo *data, int mode)
{
	if (!(data->n))
	{
		if (my_string_append(&(data->buff), "\n") == -1)
		{
			perror("echo::");
			free(data->buff);
			exit_status(EXIT_FAILURE, mode);
		}
	}
	return (0);
}

static void	echo_scan_arg(t_echo *data, char *av, int mode)
{
	if (scan_synp(data, av))
	{
		if (addarg(data, av) == -1)
		{
			free(data->buff);
			exit_status(EXIT_FAILURE, mode);
		}
		data->flag = 1;
	}
}

void	echo(int ac, char **av, int mode)
{
	t_echo	data;
	int		i;

	data.buff = (char *)0;
	data.n = 0;
	data.flag = 0;
	i = 0;
	while (++i < ac)
		echo_scan_arg(&data, av[i], mode);
	addbn(&data, mode);
	i = EXIT_SUCCESS;
	if (data.buff && write(STDOUT_FILENO, data.buff, my_string_len(data.buff)) == -1)
		i = EXIT_FAILURE;
	free(data.buff);
	if (i == EXIT_FAILURE)
		perror("echo::");
	exit_status(i, mode);
}
