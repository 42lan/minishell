/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:02:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/11 18:38:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_env()
**
** RETURN VALUES
**	Upon successful completion, the value 0 is returned.
*/

extern char		**environ;

int				builtin_env(void)
{
	int			i;

	i = -1;
	if (!environ || !*environ)
		return (1);
	while (environ[++i])
		ft_printf("%s\n", environ[i]);
	return (0);
}
