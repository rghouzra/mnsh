/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_term_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:48:43 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/22 01:01:44 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static void	expand_node_(char *sres, char **r, t_my_list **new, char *s)
{
	int		i;
	char	**words;

	words = ft_alphasplit2(s, 0, (t_alphasplit){0, 0, 0, 0, 0, 0, 0, 0, 0});
	if (!words)
		exit(EXIT_FAILURE);
	i = 0;
	while (words[i])
	{
		r = expand_word(&words[i++]);
		if (!r)
			continue ;
		append_res(&sres, new, r);
		my_strings_free(&r);
	}
	if (sres)
	{
		if (my_list_push_back(new, my_list_new_elem(my_string_dup(sres),
					free_string)) == -1)
			exit(EXIT_FAILURE);
		free(sres);
	}
	my_strings_free(&words);
}

void	expand_node(t_my_list **new, char *s)
{
	char	*sres;
	char	**r;

	sres = (char *)0;
	r = NULL;
	expand_node_(sres, r, new, s);
}
