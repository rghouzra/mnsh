/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_split_by_first.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:20:39 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/31 00:39:03 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

static char	**dup_first(char **r, char *s)
{
	r[0] = my_string_dup(s);
	if (!r[0])
		return (free(r), NULL);
	return (r[1] = NULL, r);
}

char	**my_string_split_by_first(char *s, char *del)
{
	char	**r;
	int		index;
	int		tmp;

	r = (char **)malloc(sizeof(char *) * 2);
	if (!r)
		return (NULL);
	index = my_string_find_first(s, del);
	if (index == -1)
		return (dup_first(r, s));
	tmp = my_string_len(del);
	r[0] = my_string_sub(s, 0, index);
	r[1] = my_string_sub(s, index + tmp, my_string_len(s) - (index + tmp));
	if (!r[0])
		return (my_strings_free_count(&r, 2), NULL);
	return (r);
}
