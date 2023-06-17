/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:08:54 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/17 11:27:01 by rghouzra         ###   ########.fr       */
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
	// rl_replace_line("", 0);
	rl_redisplay();
}

static void	sigquit_handler(int sig)
{
	(void)sig;
}

void	signal_utils(void)
{
	// rl_catch_signals = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}