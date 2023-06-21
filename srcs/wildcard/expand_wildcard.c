/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:26:00 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/21 09:06:23 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static	void	add_tonew_list(t_my_list *it, t_my_list **new_list)
{
	while (it)
	{
		if (my_list_push_back(new_list, my_list_new_elem(my_string_dup((char *)it->data), free_string)) == -1)
			exit(EXIT_FAILURE);
		it = it->next;
	}
}

static void	wildcard_expand_word(t_my_list **new_list, char **word)
{
	char		*tmp;
	t_my_list	*list;

	if (**word == '\'' || **word == '"')
	{
		tmp = *word;
		remove_quotes_2(word);
		free(tmp);
		if (my_list_push_back(new_list, my_list_new_elem(my_string_dup(*word), free_string)) == -1)
			exit(EXIT_FAILURE);
		return ;
	}
	if (my_string_find_first(*word, "*") != -1)
	{
		list = pattern_matching(*word);
		add_tonew_list(list, new_list);
		my_list_clear(&list, free_string);
	}
	else if (my_list_push_back(new_list, my_list_new_elem(my_string_dup(*word), free_string)) == -1)
		exit(EXIT_FAILURE);
}

static	void	wildcard_expand_node(t_my_list **new_list, char **s)
{
	char	**words;
	char	*tmp;

	words = ft_alphasplit2(*s, 0, (t_alphasplit){0, 0, 0, 0, 0, 0, 0, 0, 0});
	if (my_strings_count(words) != 1)
	{
		tmp = *s;
		remove_quotes_2(s);
		free(tmp);
		if (my_list_push_back(new_list, my_list_new_elem(my_string_dup(*s), free_string)) == -1)
			exit(EXIT_FAILURE);
		my_strings_free(&words);
		return ;
	}
	my_strings_free(&words);
	wildcard_expand_word(new_list, s);
}

void	expand_wildcard(t_ast *term)
{
	t_my_list	*new;
	t_my_list 	*it;

	my_list_init(&new);
	it = term->value_expanded;
	while (it)
	{
		wildcard_expand_node(&new, (char **)(&(it->data)));
		it = it->next;
	}
	my_list_clear(&(term->value_expanded), free_string);
	term->value_expanded = new;
}
