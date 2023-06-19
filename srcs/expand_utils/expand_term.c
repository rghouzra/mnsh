/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:30:22 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/19 14:57:13 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static char	**expand_word(char **s)
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

static void	append_res(char **s, t_my_list **new, char **r)
{
	int	i;

	i = -1;
	while (r[++i])
	{
		if (i)
		{
			if (my_list_push_back(new, my_list_new_elem(my_string_dup(*s), free_string)) == -1)
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

static void	expand_node(t_my_list **new, char *s)
{
	char	*sres;
	char	**r;
	char	**words;
	int		i;

	sres = (char *)0;
	words = ft_alphasplit2(s, 0, (t_alphasplit){0, 0, 0, 0, 0, 0, 0, 0, 0});
	if (!words)
		exit(EXIT_FAILURE);
	printf("this is {%s}\n", s);
	for (int i = 0; words[i]; i++)
		printf("{%s}->", words[i]);
	printf("{null}\n");
	i = 0;
	while (words[i])
	{
		r = expand_word(&words[i++]);
		if (!r)
			continue;
		append_res(&sres, new, r);
		my_strings_free(&r);
	}
	if (sres)
	{
		if (my_list_push_back(new, my_list_new_elem(my_string_dup(sres), free_string)) == -1)
			exit(EXIT_FAILURE);
		free(sres);
	}
	my_strings_free(&words);
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
	t_my_list *it;

	put_to_list(term);

	expand_list(&term->value_expanded);

	printf("List Result\n");
	it = term->value_expanded;
	while (it)
	{
		printf("{%s}->", it->data);
		it = it->next;
	}
	printf("{null}\n");
}
