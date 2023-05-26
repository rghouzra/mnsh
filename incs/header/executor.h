/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:16:13 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/26 16:45:56 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "header.h"

typedef struct s_exec
{
	int		i;
	char	**paths;
	char	*cmd;
}			t_exec;

typedef struct s_io
{
	int		input;
	int		output;
	int		be_dupped;
	int		stream;
	int		increment;
}			t_io;

typedef struct s_openpar
{
	int		flags;
	int		permissions;
	int		stream;
}			t_openpar;

char		*execute(char **cmnds);
void		eval_tree(t_ast *tree, int is_child, t_io x);
int			check_access(char *path, int which);
void		handle_rediro(t_ast *tree, t_io x, int is_child);
void		handle_rediri(t_ast *tree, t_io x, int is_child);
void		get_virual_operands(char *operands, t_openpar x, int is_running);
void		handle_append(t_ast *tree, t_io x, int is_child);

#endif
