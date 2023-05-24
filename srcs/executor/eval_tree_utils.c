/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_tree_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:54:48 by rghouzra          #+#    #+#             */
/*   Updated: 2023/02/26 14:57:07 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_is_bultin(char *s)
{
	if (!ft_strncmp(s, "echo", ft_strlen("echo")))
		return (0);
	if (!ft_strncmp(s, "cd", ft_strlen("cd")))
		return (1);
	if (!ft_strncmp(s, "export", ft_strlen("export")))
		return (2);
	if (!ft_strncmp(s, "pwd", ft_strlen("pwd")))
		return (3);
	if (!ft_strncmp(s, "unset", ft_strlen("unset")))
		return (4);
	if (!ft_strncmp(s, "env", ft_strlen("env")))
		return (5);
	if (!ft_strncmp(s, "exit", ft_strlen("exit")))
		return (6);
	return (-1);
}
