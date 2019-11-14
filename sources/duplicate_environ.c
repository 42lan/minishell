/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_environ.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:36:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/14 14:30:01 by amalsago         ###   ########.fr       */
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

char			**duplicate_environ(void)
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
