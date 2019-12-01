/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:33:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/01 16:02:21 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char			**environ;

void				increment_level(void)
{
	static int		lvl;

	lvl = ft_atoi(ft_getenv("SHLVL"));
	ft_setenv("SHLVL", ft_itoa(lvl + 1), 1);
}

int					execute_command(const char *realpath, char **command)
{
	if (check_access(realpath))
	{
		if (ft_strequ(realpath, "./minishell"))
			increment_level();
		if ((execve(realpath, command, environ)) < 0)
			ft_perror("minishell: execve() failed in child_handler()");
	}
	exit(EXIT_FAILURE);
}
