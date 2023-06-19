/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:50:34 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/15 19:48:34 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*generate_filename(void)
{
	char *file_name_base;
	char *number;
	int i;

	i = 0;
	file_name_base = ft_strdup("/tmp/.heredoc");
	while (access(file_name_base, F_OK) == 0)
	{
		free(file_name_base);
		file_name_base = ft_strdup("/tmp/.heredoc");
		number = ft_itoa(i);
		file_name_base = ft_strjoin(file_name_base, number, 2);
		i++;
	}
	return (file_name_base);
}