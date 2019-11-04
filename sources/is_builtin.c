/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:08:25 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 12:26:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_builtin(const char *command)
{
	int		i;

	i = -1;
	while(g_builtins[++i])
		if (ft_strequ(command, g_builtins[i]))
			return (1);
	return (0);
}
