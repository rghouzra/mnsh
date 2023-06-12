/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:19:42 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/12 18:33:07 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

char	*envgetvalue(char *key);
int		env_var_exist(char *key);
int		export_var_exist(char *key);
int		env_var_update(char *key, char *new_value);
int		export_var_update(char *key, char *new_value);

void	expand_term(t_ast *term);
int		is_valid_char(char c, int pos);

#endif
