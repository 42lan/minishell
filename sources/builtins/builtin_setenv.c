/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:32:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/14 15:44:37 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_setenv()
**	ft_setenv()
**
** RETURN VALUES
**	builtin_setenv()
**		Upon successful completion, the value 1 is returned otherwise 0.
**	ft_setenv()
**		Upon successful completion, the value 1 is returned otherwise 0.
*/

extern char		**environ;

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
		if (ft_setenv(name, value, 1) != 1)
		{
			ft_strdel(&trimmed);
			return (0);
		}
	}
	ft_strdel(&trimmed);
	return (1);
}
