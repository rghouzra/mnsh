/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:55:55 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/08 16:03:55 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

int	exit_status(int status, int mode)
{
	if (mode == YES_EXIT)
		exit(status);
	g_mnsh->exit_status = status;
	return (status);
}
