/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:19:30 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/27 11:22:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_commands(char **commands)
{
	int		i;

	i = -1;
	if (commands && *commands)
		while (commands[++i])
			ft_printf("%d |%s|\n", i, commands[i]);
}
