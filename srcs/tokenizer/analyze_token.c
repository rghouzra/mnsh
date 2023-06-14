/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:27:30 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/14 14:15:40 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	analyze_token(t_list *token)
{
	if (token == NULL || token->next == NULL)
		return ;
	while (token->next)
	{
		if (token->type == heredoc_i && token->next->type == WORD)
			read_heredoc(token->next->content);
		token = token->next;
	}
}
