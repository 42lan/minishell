/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:45:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/21 14:24:02 by amalsago         ###   ########.fr       */
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

static void		nl_prompt(void)
{
	ft_putchar('\n');
	display_prompt();
}

static void		sigint_handler(void)
{
	signal(SIGINT, (void*)nl_prompt);
}

static void		minishell(char *line)
{
	int			i;
	char		**commands;

	i = -1;
	write_history(line);
	commands = parse_input(line);
	while (commands[++i])
		if (execute(commands[i]) == 0)
			ft_perror("Failed to execute command");
	ft_arraydel(commands);
}

int				main(void)
{
	char		*line;

	environ = setup_environ();
	sigint_handler();
	while (1)
	{
		display_prompt();
		line = get_input();
		if (line)
		{
			if (*line)
				minishell(line);
			ft_strdel(&line);
		}
		else
			ft_putchar('\n');

	}
	ft_strdel(&line);
	return (0);
}
