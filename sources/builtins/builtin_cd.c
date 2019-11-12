/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:08:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/12 18:47:43 by amalsago         ###   ########.fr       */
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

extern char		**environ;

int				builtin_cd(const char *line)
{
	char		*cwd;
	const char	*path;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	path = line + ft_strspn(line, "cd ");
	if (ft_strequ(path, "\0"))
		path = ft_getenv("HOME");
	else if (ft_strnequ(path, "-", 1))
		path = ft_getenv("OLDPWD");
	else if (ft_strnequ(path, "./", 2))
		path = form_path(cwd, path);
	if (chdir(path) < 0)
	{
		print_enoent(path);
		return (0);
	}
	int i = -1;
	while (environ[++i])
		if (ft_strnequ(environ[i], "OLDPWD", 6))
		{
			ft_unsetenv("OLDPWD");
			ft_printf(">>>%d\n", ft_setenv("OLDPWD", cwd));
		}
	i = -1;
	while (environ[++i])
		if (ft_strnequ(environ[i], "PWD", 6))
		{
			ft_unsetenv("PWD");
			ft_setenv("PWD", path);
		}
	//ft_setenv("PWD", path);
	// builtin_setenv(PWD, cwd, 1);
	//ft_strdel(&path);
	return (1);
}
