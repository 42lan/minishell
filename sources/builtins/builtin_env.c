/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:02:04 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/18 18:10:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_env() prints a list of environment variables or run another utility
**	in an altered environment without having to modify the currently existing
**	environment (the last one isn't implemented in current version of minishell)
**
** RETURN VALUES
**	Upon successful completion, the value 0 is returned.
*/

extern int			g_exit_status;

int					builtin_env(void)
{
	int				i;
	extern char		**environ;

	i = -1;
	if (!environ || !*environ)
	{
		g_exit_status = 1;
		return (1);
	}
	while (environ[++i])
		ft_printf("%s\n", environ[i]);
	return (0);
}
