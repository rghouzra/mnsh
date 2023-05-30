/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:02:11 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/25 20:32:35 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	char_is_op(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '&' || c == '('
		|| c == ')');
}

int	is_an_op(char line)
{
	if (char_is_op(line))
		return (1);
	return (0);
}

t_tokentype	invalid_token(char *line)
{
	if (!ft_strncmp(line, "&", ft_strlen("&")))
		return (NONE);
	if (!ft_strncmp(line, ";", ft_strlen(";")))
		return (NONE);
	return (NONE);
}

t_tokentype	get_op_token_type(char *line)
{
	if (!line)
		return (NONE);
	if (!ft_strncmp(line, "||", 2))
		return (OR_CMD_CHAIN);
	if (!ft_strncmp(line, "|", ft_strlen("|")))
		return (PIPE);
	if (!ft_strncmp(line, "<", ft_strlen("<")))
		return (redir_i);
	if (!ft_strncmp(line, "<<", ft_strlen("<<")))
		return (heredoc_i);
	if (!ft_strncmp(line, ">>", ft_strlen(">>")))
		return (append_o);
	if (!ft_strncmp(line, ">", ft_strlen(">")))
		return (redir_o);
	if (!ft_strncmp(line, "&&", ft_strlen("&&")))
		return (AND_CMD_CHAIN);
	if (!ft_strncmp(line, "(", ft_strlen("(")))
		return (opar);
	if (!ft_strncmp(line, ")", ft_strlen(")")))
		return (cpar);
	else
		return (invalid_token(line));
	return (NONE);
}
