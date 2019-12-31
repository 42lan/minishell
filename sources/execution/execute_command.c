/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:33:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/31 03:48:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					execute_command(const char *realpath, char **command)
{
	extern char		**environ;

	if ((execve(realpath, command, environ)) < 0)
		ft_perror("execve() failed in child_handler()");
	exit(EXIT_FAILURE);
}
