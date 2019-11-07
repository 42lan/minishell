/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:42:32 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/06 10:54:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		display_prompt(void)
{
	char	*user;

	user = ft_getenv("USER");
	if (user)
		ft_printf("%s$> ", user);
	else
		ft_printf("$> ");
}
