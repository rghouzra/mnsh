/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer3_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:19:37 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/16 06:23:37 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	helper_visualizer(const char *s, char c)
{
	int	checker;

	checker = 0;
	if (*s && *s == c)
	{
		checker = 1;
		s++;
	}
	while (*s && *s != c)
	{
		return (0);
		s++;
	}
	if (*s && *s == c)
	{
		checker = 1;
		s++;
	}
	return (checker);
}
