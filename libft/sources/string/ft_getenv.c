/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:22:45 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/14 11:57:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern char		**environ;

char			*ft_getenv(const char *name)
{
	int			i;
	int			len;
	char		*value;

	i = 0;
	value = NULL;
	while (environ[i])
	{
		len = ft_strlen(name);
		if (ft_strnequ(environ[i], name, len) && environ[i][len] == '=')
		{
			value = ft_strchr(environ[i], '=') + 1;
			break ;
		}
		i++;
	}
	return (value);
}
