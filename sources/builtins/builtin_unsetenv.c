/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:07:18 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/11 13:46:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_unsetenv()
**
** RETURN VALUES
**	Upon successful completion, the value 1 is returned otherwise
*/

extern char		**environ;

int				ft_unsetenv(const char *name)
{
	int			i;

	i = -1;
	if (!name || !*name)
	{
		ft_perror("unsetenv: Too few arguments.");
		return (0);
	}
	while (environ[++i])
		if (ft_strnequ(environ[i], name, ft_strlen(name)))
			break ;
	ft_strdel(&environ[i]);
	return (1);
}

int				builtin_unsetenv(const char *line)
{
	char		*name;

	name = ft_strtrim(line + 8);
	ft_unsetenv(name);
	ft_strdel(&name);
	return (1);
}
