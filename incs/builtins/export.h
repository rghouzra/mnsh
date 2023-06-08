/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:08:42 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/07 17:48:53 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# define KEY_VALID 0
# define KEY_NOTVALID 1

void	export(int ac, char **av, int status);
int		is_keyvalid(char *key);

#endif
