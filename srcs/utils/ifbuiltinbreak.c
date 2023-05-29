/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifbuiltinbreak.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:51:12 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/29 17:12:19 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void	ifbuiltinbreak(char **cmnds)
{
	if (!cmnds)
		return ;
	if (my_string_compare("echo", *cmnds) == LS_EQUAL)
		echo(my_strings_count(cmnds), cmnds);
}
