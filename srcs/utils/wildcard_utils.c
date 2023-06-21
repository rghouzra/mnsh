/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:28:43 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/21 10:16:57 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	file_ismatch(char *file, char *to_match)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i] && to_match[j])
	{
		if (to_match[j] == '*')
		{
			if (!to_match[j + 1])
				return (1);
			while (file[i])
			{
				if (file_ismatch(file + i, to_match + j + 1))
					return (1);
				i += 1;
			}
			return (0);
		}
		if (file[i] != to_match[j])
			return (0);
		i += 1;
		j += 1;
	}
	return ((!file[i]) && (!to_match[j]));
}

t_my_list	*pattern_matching(char *patter)
{
	DIR				*dir;
	struct dirent	*entry;
	t_my_list		*matched_pattern;

	matched_pattern = NULL;
	dir = opendir(".");
	if (dir == NULL)
		return (NULL);
	entry = readdir(dir);
	while (entry)
	{
		if (file_ismatch(entry->d_name, patter) == 1 \
			&& my_string_compare("..", entry->d_name) != LS_EQUAL \
			&& my_string_compare(".", entry->d_name) != LS_EQUAL \
			&& ((patter[0] == '*' && entry->d_name[0] != '.') \
			|| patter[0] != '*'))
		{
			if (my_list_push_back(&matched_pattern, \
			my_list_new_elem(my_string_dup(entry->d_name), free_string)) == -1)
				exit(EXIT_FAILURE);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (matched_pattern);
}
