/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:33:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 16:52:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

void			child_handler(const char *realpath, char *const *argv)
{
	if (check_access(realpath))
		if ((execve(realpath, argv, environ)) < 0)
			ft_perror("minishell: execve() failed in child_handler()");
	exit(EXIT_FAILURE);
}

int				execute_command(char **command)
{
	char		*realpath;

	if (!(realpath = find_executable(command[0])))
	{
		print_enofound(command[0]);
		ft_arraydel(command);
		return (-1);
	}
	child_handler(realpath, command);
	ft_strdel(&realpath);
	return (1);
}
