/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:15:31 by rghouzra          #+#    #+#             */
/*   Updated: 2023/03/12 18:41:43 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;
	int		counter;

	last = lst;
	counter = 0;
    if (!lst)
    {
        return NULL;
    }
	while (lst)
	{
		lst = lst->next;
		counter++;
	}
	while (counter > 1)
	{
		last = last->next;
		counter--;
	}
	return (last);
}
