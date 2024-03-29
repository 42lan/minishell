/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_level.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:45:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/18 18:10:22 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	increment_level() increments shell level if it exist, otherwise set it to 1.
*/

void		increment_level(void)
{
	int		level;

	if (ft_getenv("SHLVL") == NULL)
		ft_setenv("SHLVL", "0", OVERWRITE);
	level = ft_atoi(ft_getenv("SHLVL")) + 1;
	ft_setenv("SHLVL", ft_itoa_static(level), OVERWRITE);
}
