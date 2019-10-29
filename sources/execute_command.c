/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:33:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/29 20:01:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		child_handler(const char *command)
{
	char		**argv;
	char		*realpath;

	if ((argv = ft_strsplit(command, ' ')) == NULL)
		ft_perror_exit("ft_strsplit() failed in child_handler()");
	realpath = find_executable(argv[0]);
	if (check_access(realpath))
		if ((execve(realpath, argv, NULL)) < 0)
			ft_perror_exit("execute_command(): execve() failed");
	ft_arraydel(argv);
	ft_strdel(&realpath);
}

int			execute_command(const char *command)
{
	int		stat_loc;
	(void)stat_loc;
	pid_t	pid;

	if (!command || !*command)
		return (-1);
	if ((pid = fork()) < 0)
		ft_perror_exit("fork() failed in execute_command.c");
	else if (pid == 0)
	{
		//ft_printf("Child execution\n");
		/* CHILD EXECUTES COMMAND */
		child_handler(command);
		// Need to exit
	}
	else
	{
		//ft_printf("Parent execution\n");
		/* PARENT WAITS WHILE HIS CHILD EXECVE COMMAND */
		// parent_handler();
		wait(NULL);
	}
	return (1);
}
