/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:26:19 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/25 20:32:40 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*handle_dq(const char *line, int **index, int *check)
{
	int		first;
	char	*value;

	first = **index;
	while (line[**index])
	{
		if (line[**index] && line[**index + 1] == DQ)
			break ;
		**index = **index + 1;
	}
	if (line[**index] && line[**index + 1] == DQ)
	{
		*check = 1;
		value = ft_substr(line, first, **(index));
	}
	else
	{
		*check = -1;
		value = NULL;
	}
	printf("%s\n", value);
	return (value);
}

char	*handle_sq(const char *line, int **index, int *check)
{
	int		first;
	char	*value;

	first = **index;
	while (line[**index])
	{
		if (line[**index] == SQ)
			break ;
		**index = **index + 1;
	}
	if (line[**index] == SQ)
	{
		*check = 2;
		value = ft_substr(line, first, **index - 1);
	}
	else
	{
		*check = -1;
		value = NULL;
	}
	return (value);
}
