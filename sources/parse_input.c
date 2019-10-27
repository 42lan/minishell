/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:24:02 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/27 11:07:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**parse_input(const char *line)
{
	int		i;
	char	*tmp;
	char	**commands;

	i = 0;
	commands = ft_strsplit(line, ';');
	while (commands[i])
	{
		//ft_printf("1 [%s]\n", commands[i]);
		tmp = commands[i];
		commands[i] = ft_strtrim(commands[i]);
		ft_strdel(&tmp);
		//ft_printf("2 [%s]\n", commands[i]);
		++i;
	}
	return (commands);
}
