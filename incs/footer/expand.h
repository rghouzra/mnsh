/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:19:42 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/22 01:03:56 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

char	*envgetvalue(char *key);
int		env_var_exist(char *key);
int		export_var_exist(char *key);
int		env_var_update(char *key, char *new_value);
int		export_var_update(char *key, char *new_value);

void	put_to_list(t_ast *term);

void	expand_term(t_ast *term);

int		is_valid_char(char c, int pos);
int		append_value(char **new, char *key);

char	**expand_double_quotes(char **s);
char	**expand_single_quotes(char **s);

char	*expand(char **s);
void	expand_node(t_my_list **new, char *s);

void	append_res(char **s, t_my_list **new, char **r);
void	expand_wildcard(t_ast *term);
char	**expand_word(char **s);

#endif
