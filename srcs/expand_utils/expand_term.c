/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:30:22 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/17 23:30:46 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"
/*
static int	to_expand(char **s, char **new, int i)
{
	char	*key;
	int		j;

	key = (char *)0;
	j = i;
	while (is_valid_char((*s)[i], ((i)-j)))
	{
		if (my_string_append_char(&key, (*s)[i]) == -1)
			exit(EXIT_FAILURE);
		i++;
	}
	if (i == j)
	{
		if ((*s)[i] == '?')
		{
			key = ft_itoa(g_mnsh->exit_status);
			if (!key)
				exit(EXIT_FAILURE);
			if (my_string_append(new, key) == -1)
				exit(EXIT_FAILURE);
			return (++i);
		}
		if (my_string_append_char(new, '$') == -1)
			exit(EXIT_FAILURE);
		return (i);
	}
	else if (append_value(new, key) == -1)
		exit(EXIT_FAILURE);
	return (free(key), i);
}

static void	expand_word(char **s)
{
	char	*new;
	int		i;

	if (**s == '\'')
		return ;
	new = (char *)0;
	i = 0;
	if (!(*s)[i])
		return ;
	while ((*s)[i])
	{
		if ((*s)[i] == '$')
			i = to_expand(s, &new, i + 1);
		else
		{
			if (my_string_append_char(&new, (*s)[i]) == -1)
				exit(EXIT_FAILURE);
			i++;
		}
	}
	free(*s);
	*s = new;
}

static void	expand_line(char **org, char **s)
{
	char	*new;
	int		i;

	new = (char *)0;
	i = -1;
	while (s[++i])
	{
		expand_word(&s[i]);
		if (s[i] && (my_string_append(&new, s[i]) == -1))
			exit(EXIT_FAILURE);
	}
	my_strings_free(&s);
	free(*org);
	*org = new;
}
*/

static t_my_list	*trans_to_list(t_ast *term)
{
	t_my_list	*cmnds;
	t_list		*n;

	my_list_init(&cmnds);
	if (my_list_push_back(&cmnds, my_list_new_elem(my_string_dup(term->value),
				free_string)) == -1)
		exit(EXIT_FAILURE);
	n = term->next_word;
	while (n)
	{
		if (my_list_push_back(&cmnds,
				my_list_new_elem(my_string_dup(n->content), free_string)) == -1)
			exit(EXIT_FAILURE);
		n = n->next_word;
	}
	return (cmnds);
}

static void	expand_word(t_my_list **new, char **word)
{
	int	i;

	if (**word == '\'')
	{
		if (remove_quotes(word) == -1)
			exit(EXIT_FAILURE);
		if (my_list_push_back(new, my_list_new_elem(my_string_dup(*word), free_string)) == -1)
			exit(EXIT_FAILURE);
	}
	else if (**word == '"')
	{
		if (remove_quotes(word) == -1)
			exit(EXIT_FAILURE);
		
	}

}

static void	expand_line(t_my_list **new, char *line)
{
	char	**words;
	int		i;

	words = ft_alphasplit2(line, 0, (t_alphasplit){0, 0, 0, 0, 0, 0, 0, 0, 0});
	if (!words)
		exit(EXIT_FAILURE);
	i = 0;
	while (words[i])
		expand_word(new, &words[i++]);
}

static	void	to_expand(t_my_list **list)
{
	t_my_list	*new;
	t_my_list 	*it;

	my_list_init(&new);
	it = *list;
	while (it)
	{
		expand_line(&new, it->data);
		it = it->next;
	}
}

char **expand_term(t_ast *term)
{
	t_my_list	*list;
	char		**cmnds;


	cmnds = NULL;
	list = trans_to_list(term);
	to_expand(&list);
	return (cmnds);
}
