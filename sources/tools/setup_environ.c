/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_environ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:36:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/26 06:20:25 by amalsago         ###   ########.fr       */
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
		ft_setenv("SHELL", "minishell", OVERWRITE);
		ft_setenv("SHLVL", "1", OVERWRITE);
		ft_setenv("PATH", "/bin:/usr/bin:/sbin:/usr/sbin", OVERWRITE);
		data->environ = environ;
	}
	else
		if (!(data->environ = duplicate_environ())) // MALLOC
			ft_perror_exit("duplicate_environ() failed in setup_environ()");
	return (data->environ);
}
