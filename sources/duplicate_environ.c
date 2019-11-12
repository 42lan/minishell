/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_environ.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:36:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/12 18:39:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

static int		total_rows(char **environ)
{
	int			rows;

	rows = 0;
	while (environ[rows])
		rows++;
	return (rows);
}

char			**duplicate_environ(void)
{
	int			i;
	char		**new_environ;

	i = -1;
	if (!(new_environ = ft_strnew2d(total_rows(environ) + 1)))
		return (NULL);
	while (environ[++i])
		new_environ[i] = ft_strdup(environ[i]);
	return (new_environ);
}
