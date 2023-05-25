/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:57:25 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/25 20:04:08 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_token_word(char *line, int *ind)
{
	t_list	*token;
	int		i;

	i = *ind;
	while (line[i] && !is_an_op(line[i]))
		i++;
    token = ft_tokennew(ft_substr(line, *ind, i - *ind), WORD);
 	*ind = i;
	return (token);
}

t_list	*ft_token_op(char *line, int *index, char c)
{
	t_list	*token;
	int		i;
	char	*s;
	int		j;

	j = -1;
	i = *index;
	c = line[i];
	if (c == '(' || c == ')')
		i++;
	else
		while (line[i] && line[i] == c && ++j < 2)
			i++;
	s = ft_substr(line, *index, i - *index);
	token = ft_tokennew(s, get_op_token_type(s));
	*index = i;
	return (token);
}

int	check_prev(t_list *token)
{
	if (!token)
		return (0);
	return (ft_lstlast(token)->type == WORD || ft_lstlast(token)->type == STR_SQ
		|| ft_lstlast(token)->type == STRING);
}

void	ft_lstwordadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	copy = *lst;
	while (copy->next)
		copy = copy->next;
	while (copy->next_word != NULL)
		copy = copy->next_word;
	copy->next_word = new;
}

t_list *handl_syntax_operrator(t_list **tokens, char *line, int *index, char c)
{
    t_list *token;

    token = ft_token_op(line, index, c);
    if(!token)
        return (ft_tokencleaner(tokens), printf("syntax error\n"), NULL);
    return (token);
}

void	ft_parse_str(char *line, int j, t_list **token)
{
	int	i;
    int sep;

    sep = 0;
	i = 0;
	while (line[i])
	{
		j = i;
		if (line[i] && !is_an_op(line[i]))
		{
            if (check_prev(*token))
                ft_lstwordadd_back(token, ft_token_word(line, &i));
            else
                ft_lstadd_back(token, ft_token_word(line, &i));
		}
		else if (line[i] && is_an_op(line[i]))
			ft_lstadd_back(token, handl_syntax_operrator(token, line, &i, line[i]));
        if(!line[i])
                break;
	}
}

t_list	*ft_parser(char **line)
{
	t_struct	x;

	x.token = NULL;
	x.i = -1;
	while (line[++x.i])
		ft_parse_str(line[x.i], 0, &x.token);
	return (x.token);
}

char	*get_next_word(t_list *token, char *result)
{
	char	*sep;
    t_list *next_words;

    next_words = token->next_word;
	while (next_words)
	{
		sep = ft_strdup(" ");
		result = ft_strjoin(result, ft_strjoin(sep, next_words->content, 2), 2);
		next_words = next_words->next_word;
	}
	return (result);
}

void	reconstruct_word(t_list *token)
{
	if (!token)
		return ;
	while (token)
	{
		if (token->next_word)
			token->content = get_next_word(token, token->content);
		token = token->next;
	}
}

t_list	*tokenizer(const char *line)
{
	t_list	*token;
	char	**strs;

	if (!line)
		return (NULL);
	strs = ft_alphasplit(line, ' ');
	if (!strs)
		return (NULL);
	token = ft_parser(strs);
	reconstruct_word(token);
	ft_free(strs);
	return (token);
}
