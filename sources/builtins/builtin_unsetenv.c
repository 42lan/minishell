/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 09:42:18 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/12 06:05:47 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int		g_exit_status;
void			builtin_unsetenv(const char *line)
{
	int			i;
	char		**variables;

	i = -1;
	variables = ft_strsplit_spaces(line);
	if (variables)
		while (variables[++i])
			ft_unsetenv(variables[i]);
	else
		g_exit_status = ft_perror(E_FEWARGS);
	ft_strarraydel(&variables);
}
