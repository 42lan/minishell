/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:08:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/26 23:08:34 by amalsago         ###   ########.fr       */
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

static const char	*determine_path(const char *line, const char *cwd)
{
	const char		*path;

	path = line + ft_strspn(line, "cd ");
	if (ft_strequ(path, "\0"))
	{
		if (!(path = ft_getenv("HOME")))
			ft_perror("minishell: cd: HOME not set");
	}
	else if (ft_strnequ(path, "-", 1))
		path = ft_getenv("OLDPWD");
	else if (ft_strnequ(path, "./", 2))
		path = form_path(cwd, path + 2);
	return (path);
}

int					builtin_cd(const char *line)
{
	const char		*path;
	char			*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (!(path = determine_path(line, cwd))
		|| check_access(path) != 0 || chdir(path) < 0)
	{
		ft_strdel(&cwd);
		return (0);
	}
	ft_setenv("OLDPWD", (cwd) ? cwd : ft_getenv("PWD"), OVERWRITE);
	ft_setenv("PWD", path, OVERWRITE);
	ft_strdel(&cwd);
	return (1);
}
