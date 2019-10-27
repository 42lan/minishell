/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:33:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/27 15:58:54 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		child_handler(const char *command)
{
	char		**argv;
	char		*realpath;

	argv = ft_strsplit(command, ' ');
	realpath = find_executable(argv[0]);
	if ((execve(realpath, argv, NULL)) < 0)
		ft_print_error_and_exit("execute_command(): execve() failed\n");
}

int			execute_command(const char *command)
{
	pid_t	pid;

	if (!command || !*command)
		return (-1);
	pid = fork();
	if (pid < 0)
		ft_print_error_and_exit("execute_command(): fork() failed\n");
	else if (pid == 0)
	{
		/* CHILD EXECUTES COMMAND */
		child_handler(command);
	}
	else
	{
		/* PARENT WAITS WHILE HIS CHILD EXECVE COMMAND */
	}
	return (1);
}
