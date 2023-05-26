/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:30:50 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/26 15:17:06 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNSH_H
# define MNSH_H

#include "header.h"
#include "footer.h"


typedef struct s_minishell
{
	t_my_list	*env_list;
	t_my_list	*export_list;
	char		**paths_list;
	int			exit_status;

}				t_minishell;

t_minishell		*g_mnsh;

#endif
