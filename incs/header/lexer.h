/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:09:15 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/16 06:09:16 by rghouzra         ###   ########.fr       */
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
