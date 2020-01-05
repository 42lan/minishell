/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:32:36 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/05 22:35:31 by amalsago         ###   ########.fr       */
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

int					builtin_setenv(t_msh *data, const char *line)
{
	int				ret;
	char			*name;
	char			*value;
	char			*variable;
	extern char		**environ;

	ret = 1;
	variable = ft_strtrim(line);
	if (!*variable)
		builtin_env();
	else
	{
		name = ft_strtok(variable, " \t");
		value = (variable[ft_strlen(name) + 1] == '"')
				? ft_strctrim(variable + ft_strlen(name) + 1, '"')
				: ft_strctrim(ft_strtok(NULL, " \t"), ' ');
		ret = ft_setenv(name, value, OVERWRITE);
		data->environ = environ;
		ft_strdel(&value);
	}
	ft_strdel(&variable);
	return (ret);
}
