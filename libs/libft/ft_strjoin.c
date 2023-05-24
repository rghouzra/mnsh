/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:23:04 by rghouzra          #+#    #+#             */
/*   Updated: 2023/02/28 19:23:11 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int option)
{
	int		i;
	int		j;
	int		length;
	char	*strings;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	strings = (char *)ft_malloc(length * sizeof(char));
	while (s1[++i])
		*(strings + i) = *(s1 + i);
	while (*(s2 + j))
		strings[i++] = s2[j++];
	*(strings + i) = '\0';
	if (option)
		free((void *)s1);
	if (option == 2)
		free((void *)s2);
	return (strings);
}
