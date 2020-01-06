/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_logtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 06:47:29 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/06 14:34:57 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	display_logtime() display current time when minishell was executed.
**
** RETURN VALUES
**	This function do not return a value.
*/

void			display_logtime(void)
{
	time_t		current_time;

	current_time = time(NULL);
	ft_printf(SGR_INVERSE);
	ft_printf(SGR_INVERSE"minishell login time: %s", ctime(&current_time));
	ft_printf(SGR_INVERSEOFF);
}
