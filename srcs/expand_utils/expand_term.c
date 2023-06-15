/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:30:22 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/15 18:05:27 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	to_expand(char **s, char **new, int i)
{
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

void	expand_term(t_ast *term)
{
	char	**line;
	t_list	*n;

	line = ft_alphasplit2(term->value, 0);
	if (!line)
		exit(EXIT_FAILURE);
	expand_line((char **)(&term->value), line);
	n = term->next_word;
	while(n)
	{
		line = ft_alphasplit2(n->content, 0);
		if (!line)
			exit(EXIT_FAILURE);
		expand_line((char **)(&n->content), line);
		n = n->next_word;
	}
}
