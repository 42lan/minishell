/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:33:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 16:44:34 by amalsago         ###   ########.fr       */
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
	pid_t		pid;
	char		*realpath;

	if (!(realpath = find_executable(command[0])))
	{
		print_enofound(command[0]);
		ft_arraydel(command);
		return (-1);
	}
	if ((pid = fork()) < 0)
	{
		ft_perror("minishell: fork() failed in execute_command()");
		ft_arraydel(command);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		child_handler(realpath, command);
	waitpid(pid, NULL, 0);
	ft_arraydel(command);
	return (1);
}
