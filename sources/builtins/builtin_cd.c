/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:08:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/29 22:51:38 by amalsago         ###   ########.fr       */
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
	path_from_line = ft_strdup(line + ft_strspn(line, "cd ")); // MALLOC
	if (ft_strequ(path_from_line, "\0"))
	{
		if ((home = ft_getenv("HOME")))
			path = ft_strdup(home); // MALLOC
		else
			ft_perror("minishell: cd: HOME not set");
	}
	else if (ft_strnequ(path_from_line, "-", 1))
		path = ft_strdup(ft_getenv("OLDPWD")); // MALLOC
	else if (ft_strnequ(path_from_line, "./", 2))
		path = form_path(cwd, path_from_line + 2); // MALLOC
	else
		path = ft_strdup(path_from_line); // MALLOC
	ft_strdel(&path_from_line);
	return (path);
}

static void		update_wd(const char *cwd)
{
	char		*newcwd;

	newcwd = getcwd(NULL, 0); // MALLOC
	ft_setenv("OLDPWD", (cwd) ? cwd : ft_getenv("PWD"), OVERWRITE);
	ft_setenv("PWD", newcwd, OVERWRITE);
	ft_strdel(&newcwd);
}

int				builtin_cd(const char *line)
{
	char		*cwd;
	char		*path;

	cwd = getcwd(NULL, 0); // MALLOC
	if (!(path = determine_path(line, cwd)) // MALLOC
		|| check_access(path) != 0 || chdir(path) < 0)
	{
		ft_strdel(&path);
		ft_strdel(&cwd);
		return (0);
	}
	update_wd(cwd);
	ft_strdel(&cwd);
	ft_strdel(&path);
	return (1);
}
