/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:44:05 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/15 14:29:33 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	is_keyvalid(char *key)
{
	int	i;

	if (!key || !(ft_isalpha(key[0]) || key[0] == '_'))
		return (0);
	i = -1;
	while (key[++i])
		if (!(ft_isalnum(key[i]) || (key[i] == '_')))
			return (0);
	return (1);
}

void	print_export(void)
{
	t_my_list	*it;

	it = g_mnsh->export_list;
	while (it)
	{
		printf("declare -x %s", ((char **)it->data)[0]);
		if (((char **)it->data)[1])
			printf("=\"%s\"", ((char **)it->data)[1]);
		printf("\n");
		it = it->next;
	}
}
