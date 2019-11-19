/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:31:37 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/16 16:46:57 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		execute_builtin(const char *command, const char *line)
{
	if (ft_strequ(command, "builtins"))
		builtin_builtins(line + 8);
	else if (ft_strequ(command, "cd"))
		builtin_cd(line);
	else if (ft_strequ(command, "echo"))
		builtin_echo(line);
	else if (ft_strequ(command, "env"))
		builtin_env();
	else if (ft_strequ(command, "exit"))
		builtin_exit();
	else if (ft_strequ(command, "setenv"))
		builtin_setenv(line + 6);
	else if (ft_strequ(command, "unsetenv"))
		ft_unsetenv(line + 8);
}
