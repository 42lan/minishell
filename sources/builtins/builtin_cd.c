/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:08:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/08 21:01:56 by amalsago         ###   ########.fr       */
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

int				builtin_cd(const char *line)
{
	char		*cwd;
	const char	*path;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	path = line + ft_strspn(line, "cd ");
	if (ft_strequ(path, "\0"))
		path = ft_getenv("HOME");
	else if (ft_strnequ(path, "./", 2))
		path = form_path(cwd, path);
	if (chdir(path) < 0)
	{
		return (0);
		print_enoent(path);
	}
	// builtin_setenv(OLDPWD, cwd, 1);
	// builtin_setenv(PWD, cwd, 1);
	//ft_strdel(&path);
	return (1);
}
