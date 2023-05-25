/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:18:21 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/25 18:18:33 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "header.h"

int	lexer(t_list *token);
int	is_an_operator(t_tokentype type, int which);
int	paranthesis_lexer(t_list *token);
int	is_there_invalid_op(t_list *token);
int	is_there_unexpected_token(t_list *token);

#endif
