/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:30:22 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/13 16:26:18 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	to_expand(char **s, char **new, int i)
{
	char	*key;
	int		j;

	key = (char *)0;
	j = i;
	while (is_valid_char((*s)[i], (i - j)))
	{
		if (my_string_append_char(&key, (*s)[i]) == -1)
			exit(EXIT_FAILURE);
		i++;
	}
	printf("char->%d | key->%s\n", (*s)[i], key);
	if (i == j)
	{
		if (my_string_append_char(s, '$') == -1)
			return (exit(EXIT_FAILURE), i);
		return (i);
	}
	else if (append_value(new, key) == -1)
		return (exit(EXIT_FAILURE), i);
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
		printf("$->%c\n", (*s)[i]);
		if (i > 100)
			exit(EXIT_FAILURE);
	}
	free(*s);
	*s = new;
}

void	expand_term(t_ast *term)
{
	expand_word((char **)(&(term->value)));
	t_list *n = term->next_word;
	while(n)
	{
		expand_word((char **)(&(n->content)));
		n = n->next_word;
	}
}
