/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_level.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:45:10 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/03 12:55:56 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				increment_level(void)
{
	static int		level = 0;

	level++;
	ft_printf(">>%d\n", level);
	ft_setenv("SHLVL", ft_itoa_static(level), 1);
	//ft_setenv("SHLVL", ft_itoa(level), 1); // MALLOC - NEED TO BE FREED
}
