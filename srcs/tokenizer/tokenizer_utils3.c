/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 07:55:46 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/15 09:42:00 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_my_list	*my_tokennew(void *content, t_tokentype type)
{
	t_my_list	*new;

	new = (t_my_list *)ft_malloc(sizeof(t_my_list));
	if (new)
	{
		new->data = content;
		new->next = NULL;
	}
	return (new);
}

t_my_list	*my_token_quote(char *line, int *ind, char c)
{
	t_my_list	*token;
	int		i;

	i = *ind;
	i++;
	while (line[i] && line[i] != c)
		i++;
	i++;
	token = my_tokennew(ft_substr(line, *ind, i - *ind), WORD);
	*ind = i;
	return (token);
}

t_my_list	*my_token_word(char *line, int *ind)
{
	t_my_list	*token;
	int		i;

	i = *ind;
	while (line[i] && !is_an_op(line[i]) && line[i] != DQ && line[i] != SQ)
		i++;
	token = my_tokennew(ft_substr(line, *ind, i - *ind), WORD);
	*ind = i;
	return (token);
}
