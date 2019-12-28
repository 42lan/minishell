/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_logtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 06:47:29 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/28 06:47:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			display_logtime(void)
{
	time_t		current_time;

	current_time = time(NULL);
	ft_printf("minishell login time: %s", ctime(&current_time));
}
