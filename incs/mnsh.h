/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:30:50 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/20 20:42:22 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNSH_H
# define MNSH_H

# include "header.h"
# include "footer.h"

# define YES_EXIT 0
# define NO_EXIT 1

# define MNSH_PATH_MAX 4096

typedef struct s_minishell
{
	int			fd_in;
	t_my_list	*env_list;
	t_my_list	*export_list;
	int			_break;
	char		**paths_list;
	int			exit_status;
}				t_minishell;

extern t_minishell		*g_mnsh;

#endif
