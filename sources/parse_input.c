/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:24:02 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 16:55:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_input(const char *line)
{
	char	**commands;

	commands = ft_strsplit(line, ';');
	while (*commands)
	{
		*commands = ft_strtrim(*commands);
		ft_printf("->%p<-\n", *commands);
		commands++;
	}
	//char	**tokens>
	//tokens = split_into_tokens(line);
}
