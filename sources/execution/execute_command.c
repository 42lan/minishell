/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:33:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/07 14:26:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

int				execute_command(char **command)
{
	char		*realpath;

	if (!(realpath = find_executable(command[0])))
	{
		print_enofound(command[0]);
		ft_arraydel(command);
		exit(EXIT_FAILURE);
	}
	if (check_access(realpath))
		if ((execve(realpath, command, environ)) < 0)
			ft_perror("minishell: execve() failed in child_handler()");
	ft_strdel(&realpath);
	exit(EXIT_FAILURE);
}
