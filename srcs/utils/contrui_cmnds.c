/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contrui_cmnds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:05:35 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/19 14:20:44 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

char	**contrui_cmnds(t_ast *tree)
{
	t_my_list	*it;
	char		**cmnds;
	int			i;

	cmnds = (char **)ft_malloc(sizeof(char *)
			* (my_list_size(tree->value_expanded) + 1));
	if (!cmnds)
		return (perror("mnsh::malloc failed"), exit(EXIT_FAILURE), NULL);
	it = tree->value_expanded;
	i = 0;
	while (it)
	{
		cmnds[i] = my_string_dup(it->data);
		if (!cmnds[i++])
			return (perror("mnsh::malloc failed"), exit(EXIT_FAILURE), NULL);
		it = it->next;
	}
	return (cmnds[i] = (char *)0, cmnds);
}
