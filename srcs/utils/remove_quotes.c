/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:30:45 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/21 02:10:31 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

char	*remove_quotes_2(char **line)
{
	char 	*new;
	int		i;

	new = (char *)0;
	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\'')
		{
			while((*line)[++i] != '\'')
				if (my_string_append_char(&new, (*line)[i]) == -1)
					exit(EXIT_FAILURE);
		}
		else if ((*line)[i] == '"')
		{
			while((*line)[++i] != '"')
				if (my_string_append_char(&new, (*line)[i]) == -1)
					exit(EXIT_FAILURE);
		}
		else if (my_string_append_char(&new, (*line)[i]) == -1)
			exit(EXIT_FAILURE);
		i++;
	}
	*line = new;
	return (*line);
}
