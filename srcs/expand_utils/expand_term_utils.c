/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_term_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:28:17 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/21 07:25:11 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	is_valid_char(char c, int pos)
{
	if (pos == 0)
	{
		if (c != '_' && !ft_isalpha(c))
			return (0);
	}
	else
	{
		if (c != '_' && !ft_isalnum(c))
			return (0);
	}
	return (1);
}

int	append_value(char **new, char *key)
{
	char	*val;

	if (!env_var_exist(key))
		return (0);
	val = envgetvalue(key);
	if (my_string_append(new, val) == -1)
		return (-1);
	return (0);
}

void	put_to_list(t_ast *term)
{
	t_list	*n;

	if (my_list_push_back(&(term->value_expanded), my_list_new_elem(my_string_dup(term->value),
				free_string)) == -1)
		exit(EXIT_FAILURE);
	n = term->next_word;
	while (n)
	{
		if (my_list_push_back(&(term->value_expanded),
								my_list_new_elem(my_string_dup(n->content), free_string)) ==
								-1)
			exit(EXIT_FAILURE);
		n = n->next_word;
	}
}

char	**expand_single_quotes(char **s)
{
	char	**r;

	r = (char **)ft_malloc(sizeof(char *) * 2);
	*r = my_string_dup(*s);
	if (!(*r))
		exit(EXIT_FAILURE);
	return (r[1] = NULL, r);
}

char	**expand_double_quotes(char **s)
{
	char	**r;

	expand(s);
	r = (char **)ft_malloc(sizeof(char *) * 2);
	if (!(**s))
		*r = my_string_dup("");
	else
		*r = my_string_dup(*s);
	if (!(*r))
		exit(EXIT_FAILURE);
	return (r[1] = NULL, r);
}
