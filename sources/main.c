/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:45:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 16:16:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			sigint_handler(void)
{
		ft_putchar('\n');
		display_prompt();
}

int				main(void)
{
	int			i;
	char		*line;
	char		**commands;

	//clear_console();
	signal(SIGINT, (void*)sigint_handler);
	while (1)
	{
		i = -1;
		display_prompt();
		line = get_input();
		if (*line)
		{
			write_history(line);
			commands = parse_input(line);
			while (commands[++i])
				execute(commands[i]); // What if execute_command() returns <= 0?
			ft_arraydel(commands);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_printf("minishell terminated correctly\n");
	return (0);
}
