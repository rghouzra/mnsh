/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:09:07 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/21 10:12:02 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "header.h"

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
t_list		*handl_syntax_operrator(t_list **tokens, char *line, int *index,
				char c);
void		ft_lstwordadd_back(t_list **lst, t_list *new);
int			check_prev(t_list *token);
t_list		*ft_token_op(char *line, int *index, char c);
t_list		*ft_token_word(char *line, int *ind);
t_list		*ft_token_quote(char *line, int *ind, char c);
char		**ft_alphasplit(char const *s, char c, t_alphasplit x);
void		analyze_token(t_list *token);
char		**ft_alphasplit2(char const *s, char c, t_alphasplit x);

#endif
