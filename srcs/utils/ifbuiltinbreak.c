/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifbuiltinbreak.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:51:12 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/31 15:05:43 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void	ifbuiltinbreak(char **cmnds, int status)
{
	if (!cmnds)
		return ;
	if (my_string_compare("echo", *cmnds) == LS_EQUAL)
		echo(my_strings_count(cmnds), cmnds, status);
	else if (my_string_compare("env", *cmnds) == LS_EQUAL)
		env(status);
	else if (my_string_compare("export", *cmnds) == LS_EQUAL)
		export(my_strings_count(cmnds), cmnds, status);
}
