#ifndef LEXER_H
# define LEXER_H

# include "header.h"

int	lexer(t_list *token);
int	is_an_operator(t_tokentype type, int which);
int	paranthesis_lexer(t_list *token);
int	is_there_invalid_op(t_list *token);
int	is_there_unexpected_token(t_list *token);

#endif
