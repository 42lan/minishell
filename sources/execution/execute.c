/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:28:51 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/26 15:35:17 by amalsago         ###   ########.fr       */
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

int			execute(t_msh *data, const char *line)
{
	pid_t	pid;

	if (!line || !*line)
		return (0);
	if ((data->argv = ft_strsplit(line, ' ')) == NULL)
		return (0);
	if (is_builtin(data->argv[0]))
		execute_builtin(data, data->argv[0], line);
	else
	{
		if ((pid = fork()) < 0)
			return (0);
		else if (pid == 0)
			execute_command(data->argv);
		waitpid(pid, NULL, 0);
	}
	ft_strarraydel(&data->argv);
	return (1);
}
