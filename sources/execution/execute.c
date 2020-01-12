/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:28:51 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/12 06:18:20 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	execute()
**
** RETURN VALUES
**	Upon successful completion, the value 1 is returned otherwise the value 0.
*/

extern int		g_exit_status;

int				execute(t_msh *data, const char *line)
{
	int			status;
	char		*realpath;
	pid_t		pid;

	if (!line || !*line)
		return (0);
	if (is_builtin(data->argv[0]))
		execute_builtin(data, data->argv[0], line);
	else
	{
		if ((realpath = find_executable(data->argv[0])))
		{
			if ((pid = fork()) < 0)
				return (0);
			else if (pid == 0)
				execute_command(realpath, data->argv);
			waitpid(pid, &status, 0);
			g_exit_status = (status > 255) ? 1 : status;
			ft_strdel(&realpath);
		}
	}
	return (1);
}
