/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:45:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/27 13:42:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				main(int argc, char *argv[])
{
	int			i;
	char		*line;
	char		**commands;

	if (argc > 1)
		line = argv[1];
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
	(void)argc;
	(void)argv;
	return (0);
}
