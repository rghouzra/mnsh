/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:28:46 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/18 15:01:48 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	remove_quotes(char **s)
{
	char	*r;
	int		i;
	int		len;

	if (**s != '\'' && **s != '"')
		return (0);
	len = (my_string_len(*s) - 2);
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (-1);
	i = -1;
	while (++i < len)
		r[i] = (*s)[i + 1];
	r[i] = '\0';
	return (free(*s), *s = r, (**s == '\''));
}
