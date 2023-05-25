/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:26:20 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/25 18:26:37 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

typedef struct s_struct
{
	int		i;
	int		j;
	int		k;
	char	c;
	t_list	*token;
	char	*s;
}			t_struct;

typedef struct s_parser
{
	size_t	i;
	size_t	str_count;
	char	**strings;
	int		quotes_counter;
	char	cs;
}			t_parser;

typedef struct s_alphasplit
{
	size_t	i;
	size_t	str_count;
	char	**strings;
	int		quotes_counter;
	char	cs;
	size_t	length;
	char	*word;
	char	c;
	int		checker;
}			t_alphasplit;

typedef struct s_wrap
{
	char	c;
	int		i;
}			t_wrap;

int			char_is_op(char c);
int			is_an_op(char line);
t_tokentype	get_op_token_type(char *line);
t_list		*tokenizer(const char *line);
char		*handle_dq(const char *line, int **index, int *check);
char		*handle_sq(const char *line, int **index, int *check);
char		**ft_alphasplit(char const *s, char c);

#endif
