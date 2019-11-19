/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:28:51 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/08 20:52:53 by amalsago         ###   ########.fr       */
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

int			execute(const char *line)
{
	pid_t	pid;
	char	**argv;

	if (!line || !*line)
		return (0);
	if ((argv = ft_strsplit(line, ' ')) == NULL)
		return (0);
	if (is_builtin(argv[0]))
		execute_builtin(argv[0], line);
	else
	{
		if ((pid = fork()) < 0)
			return (0);
		else if (pid == 0)
			execute_command(argv);
		waitpid(pid, NULL, 0);
	}
	ft_arraydel(argv);
	return (1);
}
