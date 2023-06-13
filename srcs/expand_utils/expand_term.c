/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:30:22 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/13 01:37:29 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	to_expand(char **s, char **new, int i)
{
	char	*key;
	int		j;

	key = (char *)0;
	j = 0;
	while (is_valid_char((*s)[i], j))
	{
		if (my_string_append_char(&key, (*s)[i]) == -1)
			exit(EXIT_FAILURE);
		i++;
		j++;
	}
	if (j == 0)
		my_string_append_char(s, '$');
	return (i);
}

static void	expand_word(char **s)
{
	char	*new;
	int		i;

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
