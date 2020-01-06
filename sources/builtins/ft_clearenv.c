/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 07:07:25 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/03 08:02:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	ft_clearenv() clears all environment variables by freeing allocated memory.
**
** RETURN VALUES
**	Upon successful completion, the value 1 is returned, otherwise 0.
**
**	Standards: POSIX.1a
*/

int					ft_clearenv(void)
{
	int				i;
	extern char		**environ;

	i = -1;
	if (environ != NULL)
	{
		while (environ[++i])
			ft_strdel(&environ[i]);
		ft_strdel(environ);
		return (1);
	}
	return (0);
}
