/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:22:45 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/26 19:22:53 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

char			*ft_getenv(const char *name)
{
	char		*key;
	char		*value;

	value = NULL;
	while (*environ)
	{
		key = ft_strtok(*environ, "=");
		if (ft_strequ(key, name))
		{
			value = ft_strtok(NULL, "=");
			break ;
		}
		environ++;
	}
	return (value);
}
