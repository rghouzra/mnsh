/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:26:19 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/09 16:39:25 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_token_quote(char *line, int *ind, char c)
{
	t_list	*token;
	int		i;

	i = *ind;
	i++;
	while (line[i] && line[i] != c)
		i++;
	i++;
	token = ft_tokennew(ft_substr(line, *ind , i - *ind), WORD);
	*ind = i;
	return (token);
}

t_list	*ft_token_word(char *line, int *ind)
{
	t_list	*token;
	int		i;

	i = *ind;
	while (line[i] && !is_an_op(line[i]) && line[i] != DQ && line[i] != SQ)
		i++;
	token = ft_tokennew(ft_substr(line, *ind, i - *ind), WORD);
	*ind = i;
	return (token);
}

t_list	*ft_token_op(char *line, int *index, char c)
{
	t_list	*token;
	int		i;
	char	*s;
	int		j;

	j = -1;
	i = *index;
	c = line[i];
	if (c == '(' || c == ')')
		i++;
	else
		while (line[i] && line[i] == c && ++j < 2)
			i++;
	s = ft_substr(line, *index, i - *index);
	token = ft_tokennew(s, get_op_token_type(s));
	*index = i;
	return (token);
}

int	check_prev(t_list *token)
{
	if (!token)
		return (0);
	return (ft_lstlast(token)->type == WORD || ft_lstlast(token)->type == STR_SQ
		|| ft_lstlast(token)->type == STRING);
}

t_list	*handl_syntax_operrator(t_list **tokens, char *line, int *index, char c)
{
	t_list	*token;

	token = ft_token_op(line, index, c);
	if (!token)
		return (ft_tokencleaner(tokens), printf("syntax error\n"), NULL);
	return (token);
}
