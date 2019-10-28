/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:24:02 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/28 12:05:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**parse_input(const char *line)
{
	int		i;
	char	*tmp;
	char	**commands;

	i = 0;
	if ((commands = ft_strsplit(line, ';')) == NULL)
		ft_perror_exit("ft_strsplit() failed in parse_input.c");
	while (commands[i])
	{
		tmp = commands[i];
		if ((commands[i] = ft_strtrim(commands[i])) == NULL)
			ft_perror_exit("ft_strtrim() failed in parse_input.c");
		ft_strdel(&tmp);
		++i;
	}
	return (commands);
}
