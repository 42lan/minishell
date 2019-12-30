/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:55:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/30 02:45:36 by amalsago         ###   ########.fr       */
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

static char			*search_in_path(const char *executable)
{
	char			*realpath;
	char			*directory;
	char			*directories;

	directories = ft_strdup(ft_getenv("PATH")); // MALLOC
	directory = ft_strtok(directories, ":");
	while (directory)
	{
		realpath = ft_realpath(directory, executable); // MALLOC
		if (access(realpath, F_OK) == 0)
			break ;
		directory = ft_strtok(NULL, ":");
		ft_strdel(&realpath);
	}
	ft_strdel(&directories);
	return (realpath);
}

static char			*get_realpath(const char *executable)
{
	char			*cwd;
	char			*realpath;

	cwd = NULL;
	realpath = NULL;
	if (ft_strnequ(executable, "/", 1)
		|| ft_strnequ(executable, "./", 2)
		|| ft_strnequ(executable, "..", 2))
	{
		if (check_access(executable) != 0)
			return (NULL);
		realpath = ft_strdup(executable); // MALLOC
	}
	else if (ft_getenv("PATH"))
		realpath = search_in_path(executable); // MALLOC
	if (!realpath)
		print_enofound(executable);
	return (realpath);
}

char				*find_executable(const char *executable)
{
	struct stat		file;
	char			*realpath;

	if ((realpath = get_realpath(executable)))// MALLOC
		if (check_access(realpath) == 0)
			if (stat(realpath, &file) == 0)
			{
				if (S_ISDIR(file.st_mode))
				{
					print_isdir(realpath);
					ft_strdel(&realpath);
					return (NULL);
				}
				return (realpath);
			}
	return (NULL);
}
