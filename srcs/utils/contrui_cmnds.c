/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contrui_cmnds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:05:35 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/14 15:35:26 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	cmnds_count(t_ast *tree)
{
	int		i;
	t_list	*n;

	i = 0;
	if (tree->value)
		i++;
	n = tree->next_word;
	while (n)
	{
		if (n->content)
			i++;
		n = n->next_word;
	}
	return (i);
}

static void	puts_words(char **cmnds, t_ast *tree)
{
	int		i;
	t_list	*n;

	i = 0;
	if (tree->value)
	{
		cmnds[i] = my_string_dup(tree->value);
		if (!cmnds[i++])
			exit(EXIT_FAILURE);
	}
	n = tree->next_word;
	while (n)
	{
		if (n->content)
		{
			cmnds[i] = my_string_dup(n->content);
			if (!cmnds[i++])
				exit(EXIT_FAILURE);
		}
		n = n->next_word;
	}
}

char	**contrui_cmnds(t_ast *tree)
{
	char	**cmnds;
	int		count;

	count = cmnds_count(tree);
	cmnds = (char **)malloc(sizeof(char *) * (count + 1));
	if (!cmnds)
		exit(EXIT_FAILURE);
	return (puts_words(cmnds, tree), cmnds[count] = NULL, cmnds);
}
