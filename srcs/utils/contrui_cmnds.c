/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contrui_cmnds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:05:35 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/17 14:31:44 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static char	**trans_list(t_list *words)
{
	char		**cmnds;
	int			i;
	t_my_list	*it;

	cmnds = (char **)malloc(sizeof(char *) * (my_list_size(words) + 1));
	if (!cmnds)
		exit(EXIT_FAILURE);
	i = 0;
	it = words;
	while (it)
	{
		cmnds[i] = my_string_dup((char *)it->data);
		if (!cmnds[i++])
			exit(EXIT_FAILURE);
		it = it->next;
	}
	return (my_list_clear(&words, free_string), cmnds[i] = NULL, cmnds);
}

static int	strs_push_back(t_my_list **words, char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		if (my_list_push_back(words, my_list_new_elem(strs + i, free_string)) == -1)
			return (-1);
	return (0);
}

static int	words_push_back(t_my_list **words, char *s)
{
	char	**strs;

	if (*s != '\'' || *s != '"')
	{
		strs = my_string_split(s, " \t");
		if (!strs)
			return (-1);
		if (strs_push_back(words, strs) == -1)
			return (-1);
	}
	else
	{
		if (remove_quotes(&s) == -1)
			return (-1);
		if (my_list_push_back(words, my_list_new_elem(s, free_string)) == -1)
			return (-1);
	}
	return (0);
}

char	**contrui_cmnds(t_ast *tree)
{
	t_my_list	*words;
	t_list		*n;

	my_list_init(&words);
	if (words_push_back(&words, tree->value) == -1)
		exit(EXIT_FAILURE);
	n = tree->next_word;
	while (n)
	{
		if (words_push_back(&words, n->content) == -1)
			exit(EXIT_FAILURE);
		n = n->next_word;
	}
	return (trans_list(words));
}
