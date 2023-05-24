/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:51:33 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/24 21:56:34 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "header.h"
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# define LEFT 666
# define RIGHT 999

void	read_input(char **env);
t_ast	*shunting_algorithm(t_list *token);
int		op_priority(t_tokentype type);
void	shunting_op_handler(t_list *token, t_queue **queue, t_list **stack);
t_list	*get_stack(t_queue **queue);
t_ast	*newAstNode(t_tokentype type, void *value, t_list *next_word);
void swap_stack_operator(t_list **stack);

#endif
