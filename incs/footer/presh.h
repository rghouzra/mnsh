/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:43:43 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/09 01:59:19 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESH_H
# define PRESH_H

# include "libmystr.h"
# include "my_list.h"
# include "minishell.h"

/*
	env double matrice
	----------------------
	env 	| variable | value
			| char *   | char *

	paths command dir
	----------------
	path	| dir
			| char *
*/
int				presh(char **env);

#endif
