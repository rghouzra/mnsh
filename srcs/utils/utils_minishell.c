/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:31:54 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/25 20:31:55 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
	() (parentheses) for grouping commands
	*
	;, &, &&, || (command sequencing and execution)
	<, >, >>, <<, >&, <& (input/output redirection)
	| (pipe operator)
*/
int	get_token_priority(t_list *q)
{
	int	type;

	if (!q)
		return (-1);
	type = q->type;
	if (type == OPAR || type == CPAR)
		return (4);
	if (type == AND_CMD_CHAIN || type == OR_CMD_CHAIN)
		return (3);
	if (type == PIPE)
		return (2);
	if (type == append_o || type == heredoc_i || type == redir_i
		|| type == redir_o)
		return (1);
	return (0);
}
