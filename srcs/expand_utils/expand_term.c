/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:30:22 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/22 01:00:34 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

char	**expand_word(char **s)
{
	char	**strs;

	strs = (char **)0;
	if (**s == '\'')
		return (expand_single_quotes(s));
	if (**s == '"')
		return (expand_double_quotes(s));
	if (!expand(s))
		return (NULL);
	strs = my_string_split(*s, " \t");
	if (!strs)
		exit(EXIT_FAILURE);
	return (strs);
}

void	append_res(char **s, t_my_list **new, char **r)
{
	int	i;

	i = -1;
	while (r[++i])
	{
		if (i)
		{
			if (my_list_push_back(new, my_list_new_elem(my_string_dup(*s),
						free_string)) == -1)
				exit(EXIT_FAILURE);
			free(*s);
			*s = my_string_dup(r[i]);
			if (!*s)
				exit(EXIT_FAILURE);
		}
		else if (my_string_append(s, r[i]) == -1)
			exit(EXIT_FAILURE);
	}
}

static void	expand_list(t_my_list **list)
{
	t_my_list	*new;
	t_my_list	*it;

	my_list_init(&new);
	it = *list;
	while (it)
	{
		expand_node(&new, it->data);
		it = it->next;
	}
	my_list_clear(list, free_string);
	*list = new;
}

void	expand_term(t_ast *term)
{
	put_to_list(term);
	expand_list(&term->value_expanded);
}
