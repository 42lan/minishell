/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 09:42:18 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/06 09:42:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		builtin_unsetenv(const char *line)
{
	int		i;
	char	**variables;

	i = -1;
	variables = ft_strsplit_spaces(line);
	while (variables[++i])
		ft_unsetenv(variables[i]);
	ft_strarraydel(&variables);
}
