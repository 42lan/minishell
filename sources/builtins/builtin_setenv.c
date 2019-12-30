/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:32:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/30 04:25:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_setenv()
**
** RETURN VALUES
**	builtin_setenv()
**		Upon successful completion, the value 1 is returned otherwise 0.
*/

extern char		**environ;

int				builtin_setenv(const char *line, t_msh *data)
{
	int			ret;
	char		*name;
	char		*value;
	char		*trimmed;

	ret = 0;
	trimmed = ft_strtrim(line); // MALLOC
	if (!*trimmed)
		builtin_env();
	else
	{
		name = ft_strtok(trimmed, " \t");
		value = (trimmed[ft_strlen(name) + 1] == '"')
				? ft_strctrim(trimmed + ft_strlen(name) + 1, '"') // MALLOC
				: ft_strctrim(ft_strtok(NULL, " \t"), ' '); // MALLOC
		ret = ft_setenv(name, value, OVERWRITE);
	}
	data->environ = environ;
	ft_strdel(&trimmed);
	ft_strdel(&value);
	return (ret);
}
