/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:51:09 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/19 14:06:27 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define DQ 34
#define SQ 39

int			helper_visualizer(const char *s, char c);

static char	*ft_words(const char *s, char sep, t_alphasplit x)
{
	(void)sep;
	if (*(s + x.length) == DQ || *(s + x.length) == SQ)
	{
		x.c = *(s + x.length);
		if (helper_visualizer(s, x.c) == 1)
			x.length = 2;
		else
		{
			if (*(s + x.length) && *(s + x.length) == x.c)
				x.length++;
			while (*(s + x.length) && *(s + x.length) != x.c)
				x.length++;
			if (*(s + x.length) && *(s + x.length) == x.c)
				x.length++;
		}
	}
	else
	{
		while (*(s + x.length) && (*(s + x.length) != DQ \
			&& *(s + x.length) != SQ))
			x.length++;
	}
	x.word = (char *)ft_malloc((x.length + 1) * sizeof(char));
	return (ft_strlcpy(x.word, s, x.length + 1), x.word);
}

static int	ft_second_handle_quote(const char *s, char c)
{
	int	j;

	j = 0;
	if (s[j] && s[j] == c)
		j++;
	while (s[j] && s[j] != c)
		j++;
	if (s[j] && s[j] == c)
		j++;
	return (j);
}

static char	*to_strings(char **strings, char const *s, char c)
{
	size_t	i;
	char	cs;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			strings[i++] = ft_words(s, c, \
			(t_alphasplit){0, 0, 0, 0, 0, 0, 0, 0, 0});
		if (*s == DQ || *s == SQ)
		{
			cs = *s;
			s = s + ft_second_handle_quote(s, cs);
			if (*s == 0)
				break ;
		}
		else
		{
			while ((!(*s == c)) && *s && *s != DQ && *s != SQ)
				s++;
		}
	}
	return (strings[i] = 0, NULL);
}

static int	ft_handle_quote(const char *s, size_t *i, char c, int quotes_ctr)
{
	int	j;
	int	check_quote_ctr;

	quotes_ctr = 0;
	check_quote_ctr = 0;
	j = *i;
	if (s[j] && s[j] == c)
	{
		quotes_ctr++;
		j++;
	}
	while (s[j] && s[j] != c)
		j++;
	if (s[j] && s[j] == c)
	{
		check_quote_ctr++;
		j++;
	}
	if (!quotes_ctr || !check_quote_ctr || ((quotes_ctr % 2 == 0) \
			+ check_quote_ctr % 2 == 0) % 2 != 0)
		return (0);
	*i = j;
	return (1);
}

char	**ft_alphasplit2(char const *s, char c, t_alphasplit x)
{
	while (1)
	{
		x.quotes_counter = 0;
		while (*(s + x.i) == c && *(s + x.i))
			x.i++;
		if (*(s + x.i) == '\0')
			break ;
		x.str_count++;
		if (s[x.i] == DQ || s[x.i] == SQ)
		{
			x.cs = s[x.i];
			if (!ft_handle_quote(s, &x.i, x.cs, x.quotes_counter))
				return (printf("inclosed quotes\n"), NULL);
			if (s[x.i] == 0)
				break ;
		}
		else
		{
			while (*(s + x.i) && s[x.i] != DQ && s[x.i] != SQ)
				x.i++;
		}
	}
	x.strings = (char **)ft_malloc((x.str_count + 1) * sizeof(char *));
	return (to_strings(x.strings, s, c), x.strings);
}
