/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:28:51 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 18:39:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			execute(const char *line)
{
	pid_t	pid;
	char	**argv;

	if (!line || !*line)
		return (-1);
	if ((argv = ft_strsplit(line, ' ')) == NULL)
	{
		ft_perror("minishell: ft_strsplit() failed in execute_command()");
		return (-1);
	}
	if (ft_strequ(argv[0], "exit"))
	{
		ft_arraydel(argv);
		builtin_exit();
	}
	if ((pid = fork()) < 0)
	{
		ft_perror("minishell: fork() failed in execute_command()");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (is_builtin(argv[0]))
			execute_builtin(argv[0], line);
		else
			execute_command(argv);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, NULL, 0);
	ft_arraydel(argv);
	return (1);
}
