/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:33:04 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/18 18:12:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	execute_command() executes non-builtin commands.
*/

int					execute_command(const char *realpath, char **command)
{
	extern char		**environ;

	if ((execve(realpath, command, environ)) < 0)
		ft_perror("execve() failed in child_handler()");
	exit(EXIT_FAILURE);
}
