/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:30:22 by yrhiba            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/18 18:19:15 by yrhiba           ###   ########.fr       */
=======
/*   Updated: 2023/06/19 16:10:23 by yrhiba           ###   ########.fr       */
>>>>>>> a096863780225a0dfcc829dfa20444642532ab29
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	to_expand(char **s, char **new, int i)
{
	char	**strs;
	
	char	*key;
	int		j;

	key = (char *)0;
	j = i;
	while (is_valid_char((*s)[i], ((i) - j)))
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

static	int	escape_word(char **s)
{
	char	*r;
	int		i;
	int		len;

	if (**s != '\'' && **s != '"')
		return (0);
	len = (my_string_len(*s) - 2);
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < len)
		r[i] = (*s)[i + 1];
	r[i] = '\0';
	i = (**s == '\'');
	return (free(*s), *s = r, i);
}

static void	expand_word(char **s)
{
	char	*new;
	int		i;

	if (escape_word(s))
		return ;
	new = (char *)0;
	i = 0;
	while ((*s)[i])
	{
<<<<<<< HEAD
		// printf("{%s}->", words[i]);
		r = expand_word(&words[i++]);
		if (!r)
			continue;
		append_res(&sres, new, r);
		my_strings_free(&r);
	}
	// printf("{null}\n");
	if (sres)
	{
		if (my_list_push_back(new, my_list_new_elem(my_string_dup(sres), free_string)) == -1)
			exit(EXIT_FAILURE);
		free(sres);
=======
		if ((*s)[i] == '$')
			i = to_expand(s, &new, i + 1);
		else 
		{
			if (my_string_append_char(&new, (*s)[i]) == -1)
				exit(EXIT_FAILURE);
			i++;
		}
>>>>>>> a096863780225a0dfcc829dfa20444642532ab29
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

void	expand_term(t_ast *term)
{
<<<<<<< HEAD
	put_to_list(term);
	expand_list(&term->value_expanded);

	t_my_list *it;

	printf("List Result\n");
	it = term->value_expanded;
	while (it)
	{
		printf("{%s}->", it->data);
		it = it->next;
	}
	printf("{null}\n");
=======
  put_to_list(term);
	expand_list(&term->value_expanded);
>>>>>>> a096863780225a0dfcc829dfa20444642532ab29
}
