/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:42:32 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/11 12:23:22 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				display_prompt(void)
{
	static char		*user;

	if (!user)
		user = ft_getenv("USER");
	ft_putstr(SGR_FG_RED);
	if (user)
		ft_printf("%s$> ", user);
	else
		ft_printf("$> ");
	ft_putstr(SGR_NORMAL);
}
