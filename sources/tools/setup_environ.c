/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_environ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:36:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/24 06:40:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

static char		**duplicate_environ(void)
{
	int			i;
	char		**new_environ;

	i = -1;
	if (!(new_environ = ft_strnew2d(total_environ_rows())))
		return (NULL);
	while (environ[++i])
		new_environ[i] = ft_strdup(environ[i]);
	new_environ[i] = NULL;
	return (new_environ);
}

char			**setup_environ(t_msh *data)
{
	if (!environ || !*environ)
	{
		ft_setenv("SHELL", "minishell", 1);
		ft_setenv("SHLVL", "1", 1);
		ft_setenv("PATH", "/bin:/usr/bin:/sbin:/usr/sbin:/usr/local/bin", 1);
		data->environ = environ;
	}
	else
		data->environ = duplicate_environ(); // MALLOC
	return (data->environ);
}
