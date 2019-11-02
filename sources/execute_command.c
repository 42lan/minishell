/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:33:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/02 19:06:54 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

void			child_handler(const char *realpath, char *const argv[])
{
	if (check_access(realpath))
		if ((execve(realpath, argv, environ)) < 0)
			ft_perror("minishell: execve() failed in child_handler()");
	exit(EXIT_FAILURE);
}

int				execute_command(const char *command)
{
	pid_t		pid;
	char		**argv;
	char		*realpath;

	if (!command || !*command)
		return (-1);
	if ((argv = ft_strsplit(command, ' ')) == NULL)
	{
		ft_perror("minishell: ft_strsplit() failed in execute_command()");
		return (-1);
	}
	realpath = find_executable(argv[0]);
	if ((pid = fork()) < 0)
	{
		ft_perror("minishell: fork() failed in execute_command.c");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		child_handler(realpath, argv);
	waitpid(pid, NULL, 0);
	ft_arraydel(argv);
	ft_strdel(&realpath);
	return (1);
}
