/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:57:25 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/17 11:29:55 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_parse_str(char *line, t_list **token, int i)
{
	while (line[i])
	{
		if (line[i] && !is_an_op(line[i]) && line[i] != DQ && line[i] != SQ)
		{
			if (check_prev(*token))
				ft_lstwordadd_back(token, ft_token_word(line, &i));
			else
				ft_lstadd_back(token, ft_token_word(line, &i));
		}
		else if (line[i] == DQ || line [i] == SQ)
		{
			if (check_prev(*token))
				ft_lstwordadd_back(token, ft_token_quote(line, &i, line[i]));
			else
				ft_lstadd_back(token, ft_token_quote(line, &i, line[i]));
		}
		else if (line[i] && is_an_op(line[i]))
			ft_lstadd_back(token, handl_syntax_operrator(token, line, &i,
					line[i]));
		if (!line[i])
			break ;
	}
}

t_list	*ft_parser(char **line)
{
	t_struct	x;

	x.token = NULL;
	x.i = -1;
	while (line[++x.i])
		ft_parse_str(line[x.i], &x.token, 0);
	return (x.token);
}

t_list	*tokenizer(const char *line)
{
	t_list	*token;
	char	**strs;

	if (!line)
		return (NULL);
	add_history(line);
	strs = ft_alphasplit(line, ' ', (t_alphasplit){0, 0, 0, 0, 0, 0, 0, 0, 0});
	if (!strs)
		return (NULL);
	token = ft_parser(strs);
	analyze_token(token);
	ft_free(strs);
	return (token);
}
