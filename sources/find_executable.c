/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:55:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/29 17:24:16 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*find_executable(const char *executable)
{
	char	*realpath;
	char	*directory;
	char	*directories;

	realpath = NULL;
	if (ft_strnequ(executable, "/", 1) || ft_strnequ(executable, "./", 2))
		realpath = ft_strdup(executable);
	else
	{
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
		if (!realpath)
			realpath = ft_strdup(executable);
	}
	ft_strdel(&directories);
	return (realpath);
}
