/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:32:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/31 03:38:44 by amalsago         ###   ########.fr       */
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

int					builtin_setenv(const char *line, t_msh *data)
{
	int				ret;
	char			*name;
	char			*value;
	char			*trimmed;
	extern char		**environ;

	ret = 1;
	trimmed = ft_strtrim(line);
	if (!*trimmed)
		builtin_env();
	else
	{
		name = ft_strtok(trimmed, " \t");
		value = (trimmed[ft_strlen(name) + 1] == '"')
				? ft_strctrim(trimmed + ft_strlen(name) + 1, '"')
				: ft_strctrim(ft_strtok(NULL, " \t"), ' ');
		ret = ft_setenv(name, value, OVERWRITE);
		data->environ = environ;
		ft_strdel(&value);
	}
	ft_strdel(&trimmed);
	return (ret);
}
