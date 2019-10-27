/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:33:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/27 15:00:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			execute_command(const char *command)
{
	pid_t	pid;
	char	*directory;
	char	*directories;
	char	*realpath;
	char	**argv;

	(void)realpath;
	if (!command || !*command)
		return (-1);
	pid = fork();
	if (pid < 0)
		ft_print_error_and_exit("execute_command(): fork() failed\n");
	else if (pid == 0)
	{
		/* CHILD EXECUTES COMMAND */
		//ft_printf("\n%d I'm child (pid = %d) exucuting: %s\n\n", pid, getpid(), command);
		argv = ft_strsplit(command, ' ');
		directories = ft_getenv("PATH");
		directory = ft_strtok(directories, ":");
		while (directory)
		{
			directory = ft_strtok(NULL, ":");
			realpath = ft_realpath(directory, argv[0]);
			if (access(realpath, F_OK) == 0)
				break ;
		}
		ft_printf("realpath = %s\n", realpath);
		if ((execve(realpath, argv, NULL)) < 0)
			ft_print_error_and_exit("execute_command(): execve() failed\n");
	}
	else
	{
		/* PARENT WAITS WHILE HIS CHILD EXECVE COMMAND */
		//ft_printf("I'm parent of %d\n", pid);
	}
	return (1);
}
