/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:45:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/15 19:46:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	main()
**
** RETURN VALUES
**	Upon successful completion, the value 0 is returned.
*/

extern char		**environ;

void			nl_prompt(void)
{
	ft_putchar('\n');
	display_prompt();
}

void			signals_handler(void)
{
	signal(SIGINT, (void*)nl_prompt);
	signal(SIGTSTP, (void*)nl_prompt);
}

int				main(void)
{
	int			i;
	char		*line;
	char		**commands;

	environ = set_environ();
	signals_handler();
	while (1)
	{
		i = -1;
		display_prompt();
		line = get_input();
		if (line)
		{
			write_history(line);
			commands = parse_input(line);
			while (commands[++i])
				execute(commands[i]); // What if execute_command() returns <= 0?
			ft_arraydel(commands);
			ft_strdel(&line);
		}
		else
			ft_putchar('\n');
	}
	ft_strdel(&line);
	ft_printf("minishell terminated correctly\n");
	return (0);
}
