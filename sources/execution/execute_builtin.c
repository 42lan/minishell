/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:31:37 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/05 22:36:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtin(t_msh *data, const char *command, const char *line)
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
		builtin_exit(data);
	else if (ft_strequ(command, "pwd"))
		builtin_pwd();
	else if (ft_strequ(command, "setenv"))
		builtin_setenv(data, line + 6);
	else if (ft_strequ(command, "unsetenv"))
		ft_unsetenv(line + 8);
}
