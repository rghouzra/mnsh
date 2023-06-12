/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:30:22 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/12 20:27:31 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	to_expand(char **s, char **new, int i)
{
	char	*key;

	key = (char *)0;
	if ((*s)[i] != '$')
		return (i + 1);
	while ((*s)[i])
		i++;
	return (i);
}

static void	expand_word(char **s)
{
	char	*new;
	int		i;
	int		start;

	new = (char *)0;
	i = 0;
	while ((*s)[i])
		i = to_expand(s, &new, i);
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

/*
Not Completed
*/