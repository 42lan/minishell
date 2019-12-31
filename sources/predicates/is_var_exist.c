/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_var_exist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:55:00 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/31 03:49:16 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					is_var_exist(const char *name)
{
	int				i;
	int				len;
	extern char		**environ;

	i = -1;
	while (environ[++i])
	{
		len = ft_strlen(name);
		if (ft_strnequ(environ[i], name, len) && environ[i][len] == '=')
			return (1);
	}
	return (0);
}
