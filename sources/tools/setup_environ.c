/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_environ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:36:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/15 20:00:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

int				total_environ_rows(void)
{
	int			i;

	i = 0;
	while (environ[i])
		i++;
	return (i);
}

static char		**duplicate_environ(void)
{
	int			i;
	char		**new_environ;

	i = -1;
	if (!(new_environ = ft_strnew2d(total_environ_rows() + 1)))
		return (NULL);
	while (environ[++i])
		new_environ[i] = ft_strdup(environ[i]);
	return (new_environ);
}

char			**setup_environ(void)
{
	char		**new_environ;

	if (!environ || !*environ)
	{
		ft_setenv("SHELL", "minishell", 1);
		ft_setenv("HOME", "/Users/amalsago", 1);
		ft_setenv("PATH", "/bin:/usr/bin:/sbin:/usr/sbin:/usr/local/bin", 1);
		new_environ = environ;
	}
	else
		new_environ = duplicate_environ();
	return (new_environ);
}
