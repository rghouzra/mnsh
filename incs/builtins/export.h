/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:08:42 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/15 14:29:29 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# define KEY_VALID 0
# define KEY_NOTVALID 1
# define VAR_EXIST 0
# define VAR_NOTEXIST 1

void	export(int ac, char **av, int mode);

int		is_keyvalid(char *key);
void	print_export(void);

#endif
