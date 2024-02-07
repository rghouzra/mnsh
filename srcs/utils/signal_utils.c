/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:08:54 by rghouzra          #+#    #+#             */
/*   Updated: 2023/08/02 10:50:35 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <readline/history.h>
#include <readline/readline.h>

static void	sigint_handler(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	#if READLINE
		rl_replace_line("", 0);
	#endif
	rl_redisplay();
	g_mnsh->exit_status = -129;
}

static void	sigquit_handler(int sig)
{
	(void)sig;
}

void	signal_utils(void)
{
	#ifdef READLINE
		rl_catch_signals = 0;
	#endif
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}
