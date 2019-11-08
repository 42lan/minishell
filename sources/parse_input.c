/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:24:02 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/07 20:00:57 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**parse_input(const char *line)
{
	int		i;
	char	*tmp;
	char	**commands;

	i = 0;
	commands = NULL;
	if ((commands = ft_strsplit(line, ';')) == NULL)
		ft_perror("minishell: ft_strsplit() failed in parse_input()");
	else
		while (commands[i])
		{
			tmp = commands[i];
			if ((commands[i] = ft_strtrim(commands[i])) == NULL)
				ft_perror("minishell: ft_strtrim() failed in parse_input()");
			expand_symbols(&commands[i]);
			ft_strdel(&tmp);
			++i;
		}
	return (commands);
}
