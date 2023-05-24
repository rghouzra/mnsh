/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:19:29 by rghouzra          #+#    #+#             */
/*   Updated: 2023/02/27 06:31:12 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t byte)
{
	void	*ptr;

	ptr = malloc(byte);
	if (!ptr)
	{
		ft_putstr_fd("memory allocation failure", 2);
		exit(1);
	}
	return (ptr);
}
