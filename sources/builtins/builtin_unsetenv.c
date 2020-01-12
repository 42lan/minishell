/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 09:42:18 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/12 03:23:20 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		builtin_unsetenv(const char *line)
{
	int		i;
	char	**variables;

	i = -1;
	variables = ft_strsplit_spaces(line);
	if (variables)
		while (variables[++i])
			ft_unsetenv(variables[i]);
	else
		ft_perror(E_FEWARGS);
	ft_strarraydel(&variables);
}
