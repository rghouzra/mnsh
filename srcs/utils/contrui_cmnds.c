/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contrui_cmnds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:05:35 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/17 18:44:34 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static char	**trans_list(t_my_list *words)
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
		if (!cmnds[i])
			exit(EXIT_FAILURE);
		it = it->next;
		i++;
	}
	return (my_list_clear(&words, free_string), cmnds[i] = NULL, cmnds);
}

static int	strs_push_back(t_my_list **words, char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		if (my_list_push_back(words, my_list_new_elem(my_string_dup(strs[i]),
					free_string)) == -1)
			return (-1);
	return (0);
}

static int	words_push_back(t_my_list **words, char **s)
{
	char	**strs;

	if (**s != '\'' && **s != '"')
	{
		strs = ft_alphasplit(*s, ' ', (t_alphasplit){0, 0, 0, 0, 0, 0, 0, 0,
				0});
		if (!strs)
			return (-1);
		if (strs_push_back(words, strs) == -1)
			return (-1);
		my_strings_free(&strs);
	}
	else
	{
		printf("Before Remove Quotes->{%s}\n", *s);
		if (remove_quotes(s) == -1)
			return (-1);
		printf("After Remove Quotes->{%s}\n", *s);
		if (my_list_push_back(words, my_list_new_elem(my_string_dup(*s),
					free_string)) == -1)
			return (-1);
	}
	return (0);
}

char	**contrui_cmnds(t_ast *tree)
{
	t_my_list	*words;
	t_list		*n;
	t_my_list	*it;

	my_list_init(&words);
	if (words_push_back(&words, (char **)&tree->value) == -1)
		exit(EXIT_FAILURE);
	n = tree->next_word;
	while (n)
	{
		if (words_push_back(&words, (char **)&n->content) == -1)
			exit(EXIT_FAILURE);
		n = n->next_word;
	}
	{
		printf("Generated List Words:\n");
		it = words;
		while (it)
		{
			printf("{%s}->", it->data);
			it = it->next;
		}
		printf("{null}\n");
	}
	return (trans_list(words));
}
