/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:24:08 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/03 10:19:04 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

char	*my_string_dup(char *s)
{
	char	*r;
	int		i;

	if (!s)
		return (NULL);
	r = (char *)malloc(sizeof(char) * my_string_size(s));
	if (!r)
		return (NULL);
	i = -1;
	while (s[++i])
		r[i] = s[i];
	return (r[i] = '\0', r);
}
