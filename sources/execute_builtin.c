/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:31:37 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/06 15:43:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		execute_builtin(const char *command, const char *line)
{
	/*
	if (ft_strequ(command, "cd"))
		builtin_cd();
	*/
	if (ft_strequ(command, "echo"))
		builtin_echo(line);
	else if (ft_strequ(command, "env"))
		builtin_env();
	else if (ft_strequ(command, "exit"))
		builtin_exit();
	else if (ft_strequ(command, "setenv"))
		builtin_setenv(line);
/*
	else if (ft_strequ(command, "unsetenv"))
		builtin_unsetenv(line);
*/
}
