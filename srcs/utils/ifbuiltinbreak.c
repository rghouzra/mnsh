/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifbuiltinbreak.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:51:12 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/30 09:14:57 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void	ifbuiltinbreak(char **cmnds)
{
	if (!cmnds)
		return ;
	if (my_string_compare("echo", *cmnds) == LS_EQUAL)
		echo(my_strings_count(cmnds), cmnds);
	else if (my_string_compare("env", *cmnds) == LS_EQUAL)
		env();
	else if (my_string_compare("export", *cmnds) == LS_EQUAL)
		export(my_strings_count(cmnds), cmnds);
}
