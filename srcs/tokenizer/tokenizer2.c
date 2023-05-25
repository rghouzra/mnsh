/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:43:59 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/25 20:04:16 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DQ 34
#define SQ 39

static int	str_in_sep(char cs, char c)
{
	if (cs == c || cs == '\t')
		return (1);
	return (0);
}

int ft_wrapstring(const char *s, size_t *index, int *checker, t_wrap x)
{
    if (index)
        x.i = (*index);
    if(s[x.i] && s)
    {
        if(s[x.i] == DQ || s[x.i] == SQ)
        {
			if(checker)
           		*checker = 0;
            x.c = s[x.i];
            x.i++;
			while (s[x.i] && s[x.i] !=x.c)
				x.i = x.i + 1;
			if (s[x.i] == x.c)
			{
				*index = x.i;
				if (checker)
					*checker = 1;
                return (1);
            }
            if(checker)
                *checker = 0;
        }
    }
    return (1);
}

static char	*ft_words(const char *s, char sep)
{
	t_alphasplit	x;

	x.length = 0;
	x.i = 0;
		while (*(s + x.length) && (!str_in_sep(*(s + x.length), sep)\
        && ft_wrapstring(s, &x.length, 0, (t_wrap){0, 0})))
        {
            if(s[x.length] == 0)
                break;
			x.length++;
        }
	x.word = (char *)malloc((x.length + 1) * sizeof(char));
	return (ft_strlcpy(x.word, s, x.length + 1), x.word);
}

static char	*to_strings(char **strings, char const *s, char c)
{
	size_t	i;
    size_t  j;

    j = 0;
	i = 0;
	while (*(s + j))
	{
		while (str_in_sep(s[j], c) && s[j])
            j++;
		if (s[j])
			strings[i++] = ft_words(s + j, c);
		while (s[j] &&((!str_in_sep(s[j], c)) && (ft_wrapstring(s, &j, 0, (t_wrap){0, 0}))))
        {
            if(!s[j])
                break;
            j++;
        }
	}
	return (strings[i] = 0, NULL);
}

char	**ft_alphasplit(char const *s, char c)
{
	t_alphasplit	x;

	x.str_count = 0;
	x.i = 0;
	while (1)
	{
		x.checker = 1;
		x.quotes_counter = 0;
		while (str_in_sep(*(s + x.i), c) && *(s + x.i))
			x.i++;
		if (*(s + x.i) == '\0')
			break ;
		x.str_count++;
		while (*(s + x.i) && (!str_in_sep(*(s + x.i), c)\
        && ft_wrapstring(s, &x.i, &x.checker, (t_wrap){0, 0})))
        {
            if(x.checker == 0)
                return (printf("inclosed quote\n"), NULL);
            if (!*(s + x.i))
                break;
			x.i++;
        }
        if(x.checker == 0)
                return (printf("inclosed quote"), NULL);
        if (*(s + x.i) == '\0')
		    break ;
	}
	x.strings = (char **)ft_malloc((x.str_count + 1) * sizeof(char *));
	return (to_strings(x.strings, s, c), x.strings);
}
