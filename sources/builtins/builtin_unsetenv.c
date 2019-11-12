/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:07:18 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/11 16:48:15 by amalsago         ###   ########.fr       */
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

extern char		**environ;

int				ft_unsetenv(const char *name)
{
	int			i;
	char		*trimmed_name;

	i = -1;
	trimmed_name = ft_strtrim(name);
	if (!trimmed_name || !*trimmed_name)
	{
		ft_perror("unsetenv: Too few arguments.");
		ft_strdel(&trimmed_name);
		return (1);
	}
	while (environ[++i])
	if (ft_strnequ(environ[i], trimmed_name, ft_strlen(trimmed_name)))
			break ;
	ft_strdel(&environ[i]);
	ft_strdel(&trimmed_name);
	return (0);
}
