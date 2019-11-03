/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:45:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/03 16:52:53 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			*signals_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar('\n');
		display_prompt();
	}
	else
		ft_perror("minishell: unknown signal");
	return (NULL);
}

int				main(void)
{
	int			i;
	char		*line;
	char		**commands;

	//clear_console();
	signal(SIGINT, (void*)signals_handler);
	while (1)
	{
		i = -1;
		display_prompt();
		line = get_input();
		if (*line)
		{
			if (ft_strequ(line, "exit"))
				break ;
			write_history(line);
			commands = parse_input(line);
			while (commands[++i])
				execute_command(commands[i]); // What if execute_command() returns <= 0?
			ft_arraydel(commands);
		}
		ft_strdel(&line);
	}
	ft_printf("%s\n", line);
	ft_strdel(&line);
	ft_printf("%s\n", line);
	ft_printf("minishell terminated correctly\n");
	return (0);
}
