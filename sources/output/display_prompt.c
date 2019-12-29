/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:42:32 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/29 05:00:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	display_prompt() display a personalized prompt if USER variable is setted,
**	otherwise a simple prompt.
**
** RETURN VALUES
**	This function do not return a value.
*/

void				display_prompt(void)
{
	static char		*user;

	if (!user)
		user = ft_getenv("USER");
	if (user)
		ft_printf("%s$> ", user);
	else
		ft_printf("$> ");
}
