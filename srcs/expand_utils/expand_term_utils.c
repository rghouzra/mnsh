/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_term_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:28:17 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/12 18:33:40 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	is_valid_char(char c, int pos)
{
	if (pos == 0)
		if (c != '_' && !ft_isalpha(c))
			return (0);
	else
		if (c != '_' && !ft_isalnum(c))
			return (0);
	return (1);
}
