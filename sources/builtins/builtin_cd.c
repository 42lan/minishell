/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:08:58 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/08 09:02:43 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_cd() function changes the current working directory of the calling
**	process to the directory specified in line;
**
** RETURN VALUES
**	Upon successful completion, the value 1 is returned otherwise the value 0.
*/

static char		*determine_path(const char *line, const char *cwd)
{
	char		*home;
	char		*path;
	char		*path_from_line;

	path = NULL;
	path_from_line = ft_strdup(line + 3);
	if (ft_strequ(path_from_line, "\0"))
	{
		if ((home = ft_getenv("HOME")))
			path = ft_strdup(home);
		else
			ft_perror(E_UNSETHOME);
	}
	else if (ft_strnequ(path_from_line, "-", 1))
	{
		if ((path = ft_getenv("OLDPWD")))
			path = ft_strdup(path);
	}
	else if (ft_strnequ(path_from_line, "./", 2))
		path = form_path(cwd, path_from_line + 2);
	else
		path = ft_strdup(path_from_line);
	ft_strdel(&path_from_line);
	return (path);
}

static void		update_wd(const char *cwd)
{
	char		*newcwd;

	newcwd = getcwd(NULL, 0);
	ft_setenv("OLDPWD", (cwd) ? cwd : ft_getenv("PWD"), OVERWRITE);
	ft_setenv("PWD", newcwd, OVERWRITE);
	ft_strdel(&newcwd);
}

int				builtin_cd(const char *line)
{
	char		*cwd;
	char		*path;

	cwd = getcwd(NULL, 0);
	if ((path = determine_path(line, cwd)) && check_access(path) == 0
			&& chdir(path) >= 0)
		update_wd(cwd);
	ft_strdel(&cwd);
	ft_strdel(&path);
	return (1);
}
