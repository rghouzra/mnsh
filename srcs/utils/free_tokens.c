/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:32:53 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/21 10:21:22 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_clean_nextword(t_list **token)
{
	t_list	*tmp;

	if (!(*token))
		return ;
	while ((*token))
	{
		tmp = (*token);
		(*token) = (*token)->next_word;
		free(tmp->content);
		free(tmp);
	}
}

void	ft_tokencleaner(t_list **token)
{
	t_list	*tmp;

	if (!token || !*token)
		return ;
	while (*token)
	{
		tmp = *token;
		*token = (*token)->next;
		ft_clean_nextword(&tmp->next_word);
		free(tmp->content);
		free(tmp);
	}
	free(*token);
	*token = NULL;
}
