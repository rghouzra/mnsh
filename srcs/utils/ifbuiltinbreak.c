/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifbuiltinbreak.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:51:12 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/15 13:59:52 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	ifbuiltinbreak(char **cmnds, int mode)
{
	if (!cmnds)
		return (-1);

	// echo
	if (my_string_compare("echo", *cmnds) == LS_EQUAL)
		return (echo(my_strings_count(cmnds), cmnds, mode),
			my_strings_free(&cmnds), EXIT_SUCCESS);
	// env
	else if (my_string_compare("env", *cmnds) == LS_EQUAL)
		return (env(my_strings_count(cmnds), cmnds, mode),
			my_strings_free(&cmnds), EXIT_SUCCESS);
	// exit
	else if (my_string_compare("exit", *cmnds) == LS_EQUAL)
		return (mnsh_exit(my_strings_count(cmnds), cmnds, mode),
			my_strings_free(&cmnds), EXIT_SUCCESS);
	// export
	else if (my_string_compare("export", *cmnds) == LS_EQUAL)
		return (export(my_strings_count(cmnds), cmnds, mode),
			my_strings_free(&cmnds), EXIT_SUCCESS);

	return (EXIT_FAILURE);
}
