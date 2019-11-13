/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:32:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/13 15:58:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_setenv()
**	ft_setenv()
**		Adding 1 to length for '=' between key and value.
**		to_add = ft_strnew(length + 1);
**
** RETURN VALUES
**	builtin_setenv()
**		Upon successful completion, the value 1 is returned otherwise 0.
**	ft_setenv()
**		Upon successful completion, the value 1 is returned otherwise 0.
*/

extern char		**environ;

int				no_exceptions(const char *name)
{
	int			i;

	i = -1;
	if (!ft_isalpha(name[0]))
	{
		ft_perror("setenv: Variable name must begin with a letter.");
		return (0);
	}
	while (name[++i])
		if (!ft_isalnum(name[i]))
		{
			ft_perror("setenv: Variable name must contain alphanumeric characters.");
			return (0);
		}
	return (1);
}

int				ft_setenv(const char *name, const char *value)
{
	int			i;
	int			length;
	char		**new_environ;
	char		*to_add;

	i = -1;
	if (!no_exceptions(name))
		return (0);
	if (!(new_environ = ft_strnew2d(total_rows(environ) + 1)))
		ft_perror_exit("minishell: ft_strnew2d() failed in ft_setenv()");
	while (environ[++i])
		new_environ[i] = ft_strdup(environ[i]);
	length = (value) ? ft_strlen(name) + ft_strlen(value) : ft_strlen(name);
	to_add = ft_strnew(length + 1);
	ft_strcpy(to_add, name);
	ft_strcat(to_add, "=");
	ft_strcat(to_add, (value) ? value : "");
	new_environ[i] = to_add;
	new_environ[i + 1] = NULL;
	environ = new_environ;
	return (1);
}

int				builtin_setenv(const char *line)
{
	char		*name;
	char		*value;
	char		*trimmed;

	trimmed = ft_strtrim(line + 6);
	if (!*trimmed)
		builtin_env();
	else
	{
		name = ft_strtok(trimmed, " \t");
		value = ft_strtok(NULL, " \t");
		if (ft_setenv(name, value) != 1)
		{
			ft_strdel(&trimmed);
			return (0);
		}
	}
	ft_strdel(&trimmed);
	return (1);
}
