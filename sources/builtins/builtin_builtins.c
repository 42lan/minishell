/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:40:55 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/11 15:47:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_builtins() prints minishell builtin commands that can be executed
**	within the running minishell's process.
**
** RETURN VALUES
**	Upon successful completion, the value 0 is returned otherwise the value 1.
*/

int			builtin_builtins(const char *args)
{
	int		i;

	i = -1;
	while (ft_iswhitespace(*args))
	{
		if (*args)
		{
			ft_perror("builtins: Too many arguments.");
			return (1);
		}
		args++;
	}
	while (g_builtins[++i])
		ft_printf("%s\n", g_builtins[i]);
	return (0);
}
