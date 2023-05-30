/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokennew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:17:57 by rghouzra          #+#    #+#             */
/*   Updated: 2023/03/06 16:07:00 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_tokennew(void *content, t_tokentype type)
{
	t_list	*new;

	new = (t_list *)ft_malloc(sizeof(t_list));
	if (new)
	{
		new->content = content;
		new->type = type;
		new->next = NULL;
		new->next_word = NULL;
	}
	return (new);
}
