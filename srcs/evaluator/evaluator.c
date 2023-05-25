/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 07:06:05 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/25 18:28:30 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	delete_quotes(char *str, char quote)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (*(str + i) != quote)
		{
			str[j] = str[i];
			j++;
		}
	}
	*(str + j) = '\0';
}

void	expand_var(char *s)
{
	int	i;

	if (!s)
		return ;
}

void	evaluate_expression(t_list *token)
{
	if (token == nullptr)
		return ;
	while (token)
	{
		expand_var(token->content);
		delete_quotes((char *)token->content, DQ);
		token = token->next;
	}
}
