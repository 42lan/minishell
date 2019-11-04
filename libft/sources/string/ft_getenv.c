/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:22:45 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 19:25:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern char		**environ;

char			*ft_getenv(const char *name)
{
	int			i;
	char		*key;
	char		*value;

	i = 0;
	value = NULL;
	while (environ[i])
	{
		key = ft_strtok(environ[i], "=");
		if (ft_strequ(key, name))
		{
			value = ft_strtok(NULL, "=");
			break ;
		}
		i++;
	}
	return (value);
}
