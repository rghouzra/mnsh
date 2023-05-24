/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:16:12 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/24 22:32:58 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_valid_syntax(t_list *token)
{
	if (is_an_operator(ft_lstlast(token)->type, 1)
		|| is_an_operator(token->type, 2) == 2)
		return (0);
	return (1);
}

int check_token(t_list *token)
{
	if(!token)
		return (1);
	while(token)
	{
		if (token->type == NONE)
			return 0;
		token = token->next;
	}
	return (1);
}

int	lexer(t_list *token)
{
	if (token)
	{
		if(check_token(token) != 1)
			return (printf("syntax error\n"), 0);
		if (paranthesis_lexer(token) != 1)
			return (printf("bash: parse error near`()'\n"), 0);
		if (is_there_invalid_op(token) != 1 || check_valid_syntax(token) != 1)
			return (printf("syntax error\n"), 0);
		if (is_there_unexpected_token(token))
			return (printf("syntax error near unexpected token\n"), 0);
		return (1);
	}
	return (0);
}

/*
  ls | wc || (cat file && tail)
  ls wc | cat file tail && ||
  ls | wc > outfile && (< outfile cat -e | sort -R)
 */
