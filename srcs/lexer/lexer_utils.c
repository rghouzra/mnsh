/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:16:23 by rghouzra          #+#    #+#             */
/*   Updated: 2023/10/31 11:28:01 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_an_operator(t_tokentype type, int which)
{
	if (which == 1 && (type == redir_o || type == PIPE || type == redir_i
			|| type == AND_CMD_CHAIN || type == OR_CMD_CHAIN || type == append_o
			|| type == heredoc_i))
		return (1);
	if (which == 2 && (type == PIPE || type == OR_CMD_CHAIN \
		|| type == AND_CMD_CHAIN))
		return (2);
	if (which == 3 && (type == PIPE || type == OR_CMD_CHAIN \
		|| type == AND_CMD_CHAIN \
		|| type == redir_i || type == redir_o))
		return (3);
	if (which == 4 && (type == PIPE || type == OR_CMD_CHAIN \
		|| type == AND_CMD_CHAIN
			|| type == redir_i || type == redir_o || type == heredoc_i \
			|| type == append_o))
		return (4);
	return (0);
}

int	is_there_unexpected_token(t_list *token)
{
	if (ft_lstsize(token) == 1 && is_an_operator(token->type, 1))
		return (1);
	while (token)
	{
		if (token->next)
		{
			if (is_an_operator(token->type, 3)
				&& is_an_operator(token->next->type, 3))
				return (1);
			if (token->type == redir_i && is_an_operator(token->next->type, 2))
				return (1);
			else if ((token->type == opar && token->next->type == cpar)
				|| (token->type == cpar && token->next->type == opar))
				return (1);
			else if ((token->type == cpar && token->next->type == WORD) \
			|| (token->type == WORD && token->next->type == opar))
				return (1);
     		else if(token->type == opar && is_an_operator(token->next->type, 4))
		    	return 1;
    }
		token = token->next;
	}
	return (0);
}

int	is_there_invalid_op(t_list *token)
{
	if (token)
	{
		while (token)
		{
			if (token->type == SHARP || token->type == AND)
				return (0);
			token = token->next;
		}
	}
	return (1);
}

int	paranthesis_lexer(t_list *token)
{
	int		par;
	char	*s;
	char	*ptr;

	s = NULL;
	par = 0;
	while (token)
	{
		if (token->type == cpar || token->type == opar)
			s = ft_strjoin(s, token->content, 1);
		token = token->next;
	}
	ptr = s;
	if (s)
	{
		while (*s)
		{
			par += +(*s == '(') - (*s == ')');
			if (par < 0)
				break ;
			s++;
		}
	}
	return (free(ptr), par == 0);
}
