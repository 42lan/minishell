/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:45:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/27 18:43:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				main(void)
{
	int			i;
	char		*line;
	char		**commands;

	//clear_console();
	while (1)
	{
		i = -1;
		display_prompt();
		line = get_input();
		if (*line)
			write_history(line);
		commands = parse_input(line);
		while (commands[++i])
			execute_command(commands[i]);
		ft_arraydel(commands);
		ft_strdel(&line);
	}
	ft_printf("minishell terminated\n");
	return (0);
}
