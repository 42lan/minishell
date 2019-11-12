/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:32:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/12 18:49:16 by amalsago         ###   ########.fr       */
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
**		Upon successful completion, the value 1 is returned otherwise the value 0.
**	ft_setenv()
**		Upon successful completion, the value 1 is returned otherwise the value 0.
*/

extern char		**environ;


int				ft_setenv(const char *name, const char *value)
{
	int			i;
	int			length;
	char		**new_environ;
	char		*to_add;

	i = -1;
	if (!ft_isalpha(name[0]))
	{
		ft_perror("setenv: Variable name must begin with a letter.");
		return (0);
	}
	while (name[++i])
	{
		if (!ft_isalnum(name[i]))
		{
			ft_perror("setenv: Variable name must contain alphanumeric characters.");
			return (-1);
		}
	}
	new_environ = duplicate_environ();
	length = (value) ? ft_strlen(name) + ft_strlen(value) : ft_strlen(name);
	to_add = ft_strnew(length + 1);
	ft_strcpy(to_add, name);
	ft_strcat(to_add, "=");
	if (value)
		ft_strcat(to_add, value);
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
