/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:55:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/02 18:04:18 by amalsago         ###   ########.fr       */
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

/*
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
	if (!realpath)
		print_enofound(executable);
	ft_strdel(&directories);
	return (realpath);
}

int				is_invalid_name(const char *executable)
{
	if (ft_strequ(executable, "."))
	{
		ft_perror("minishell: .: filename argument required");
		ft_perror(".: usage: . filename [arguments]");
		return (1);
	}
	return (0);
}

char			*find_executable(const char *executable)
{
	char		*realpath;

	realpath = NULL;
	//if (is_invalid_name(executable))
	//	return (NULL);
	if (ft_strnequ(executable, "/", 1) || ft_strnequ(executable, "./", 2))
	{
		realpath = (char *)executable;
	}
	else
		realpath = (ft_getenv("PATH")) ? get_realpath(executable) : NULL;
	if (!realpath)
		return (NULL);
	return (realpath);
}
*/
static char			*get_realpath(const char *executable)
{
	char			*realpath;
	char			*directory;
	char			*directories;
	char			*cwd;

	cwd = NULL;
	realpath = NULL;
	if (ft_strnequ(executable, "/", 1))
	{
		ft_printf("Mayby it is an absolute path\n");
		if (check_access(executable) == 0)
			return (NULL);
	}
	else if (ft_getenv("PATH"))
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
		ft_strdel(&directories);
	}
	if (!realpath)
	{
		if ((cwd = getcwd(cwd, 0)))
		{
			if (ft_strnequ(executable, "./", 2))
				realpath = ft_realpath(cwd, executable + 2);
			else
				realpath = ft_realpath(cwd, executable);
			ft_strdel(&cwd);
		}
	}
	//if (!realpath)
	//	print_enofound(executable);
	return (realpath);
}

char				*find_executable(const char *executable)
{
	struct stat		file;
	char			*realpath;

	//realpath = NULL;
	//if (ft_strnequ(executable, "/", 1) || ft_strnequ(executable, "./", 2))
	//{
	//	ft_printf("------c:w\n");
	//	realpath = (char *)executable;
	//}
	//else
	//	realpath = (ft_getenv("PATH")) ? get_realpath(executable) : (char *)executable;
	realpath = get_realpath(executable);
	if (check_access(realpath))
		if (stat(realpath, &file) == 0)
		{
			if (S_ISDIR(file.st_mode))
			{
				ft_printf("minishell: %s: is a directory\n", realpath);
				return (NULL);
			}
			return (realpath);
		}
	return (NULL);
}
