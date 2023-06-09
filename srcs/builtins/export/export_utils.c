/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:44:05 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/09 14:44:05 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	is_keyvalid(char *key)
{
	int	i;


	if (!key || !(ft_isalpha(key[0]) || key[0] == '_'))
		return (KEY_NOTVALID);
	i = -1;
	while (key[++i])
		if (!(ft_isalnum(key[i]) || key[i] == '_'))
			return (KEY_NOTVALID);
	return (KEY_VALID);
}
