/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:50:41 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/17 07:06:22 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_echo() prints a line of text.
**
** RETURN VALUES
**	Upon successful completion, the value 1 is returned.
*/

int			builtin_echo(const char *line)
{
	char	*args;
	char	*token;
	int		last_char;

	args = ft_strtrim(line + 4);
	if (args[0] == '"')
	{
		last_char = ft_strlen(args);
		if (args[last_char - 1] == '"')
			args[last_char - 1] = '\0';
		ft_printf("%s\n", args + 1);
	}
	else
	{
		token = ft_strtok(args, " \t");
		while (token)
		{
			ft_printf("%s", token);
			token = ft_strtok(NULL, " \t");
			ft_putchar((token) ? ' ' : '\n');
		}
	}
	ft_strdel(&args);
	return (1);
}
