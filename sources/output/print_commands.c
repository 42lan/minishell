/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:19:30 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/29 05:35:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	print_commands() print commands that user has provided in prompt.
**
** RETURN VALUES
**	This function do not return a value.
*/

void		print_commands(char **commands)
{
	int		i;

	i = -1;
	if (commands && *commands)
		while (commands[++i])
			ft_printf("%d |%s|\n", i, commands[i]);
}
