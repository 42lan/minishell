/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:07:18 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/18 18:13:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	ft_unsetenv() removes an environment variable from the environment of the
**	calling process. The `name` argument points to a string, which contains
**  the name of the variable to be removed. Before processing, function performs
**	trimming of `name` to remove whitespaces at the beginning and the end of the
**	string.
**
** RETURN VALUES
**	Upon successful completion, the value 0 is returned otherwise the value 1.
*/

static void			shift_environ(int i)
{
	extern char		**environ;

	while (environ[++i])
	{
		environ[i - 1] = environ[i];
		environ[i] = NULL;
	}
}

int					ft_unsetenv(const char *name)
{
	int				i;
	int				len;
	extern char		**environ;

	i = -1;
	if (!name)
		return (ft_perror(E_FEWARGS));
	while (environ[++i])
	{
		len = ft_strlen(name);
		if (ft_strnequ(environ[i], name, len) && environ[i][len] == '=')
		{
			ft_strdel(&environ[i]);
			shift_environ(i);
			break ;
		}
	}
	return (0);
}
