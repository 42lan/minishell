/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:55:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/08 20:55:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	find_executable()
**	get_realpath()
**
** RETURN VALUES
**	find_executable()
**		Upon successful completion, the realpath is returned otherwise NULL.
**	get_realpath()
**		Upon successful completion, the realpath is returned otherwise NULL.
*/

static char		*get_realpath(const char *executable)
{
	char		*realpath;
	char		*directory;
	char		*directories;

	directories = ft_strdup(ft_getenv("PATH"));
	directory = ft_strtok(directories, ":");
	while (directory)
	{
		realpath = ft_realpath(directory, executable);
		if (access(realpath, F_OK) == 0)
			break ;
		directory = ft_strtok(NULL, ":");
		ft_strdel(&realpath);
	}
	ft_strdel(&directories);
	return (realpath);
}

char			*find_executable(const char *executable)
{
	char		*realpath;

	realpath = NULL;
	if (ft_strnequ(executable, "/", 1) || ft_strnequ(executable, "./", 2))
		realpath = (char *)executable;
	else
		if (ft_getenv("PATH"))
			realpath = get_realpath(executable);
	return (realpath);
}
