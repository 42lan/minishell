/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:45:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/26 06:02:47 by amalsago         ###   ########.fr       */
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

static void		nl_prompt(int signum)
{
	(void)signum;
	ft_putchar('\n');
	display_prompt();
}

static void		sigint_handler()
{
	signal(SIGINT, nl_prompt);
}
void			initialize_msh(t_msh *data)
{
	data->line = NULL;
	data->history_file = NULL;
	data->argv = NULL;
	data->environ = NULL;
	data->commands = NULL;
}

static void		minishell(t_msh *data)
{
	int			i;

	i = -1;
	write_history(data, data->line);
	data->commands = parse_input(data->line); // MALLOC
	while (data->commands[++i])
		if ((data->argv = ft_strsplit(data->commands[i], ' '))) // MALLOC
		{
			execute(data, data->commands[i]);
			ft_strarraydel(&data->argv);
		}
	ft_strarraydel(&data->commands);
}

int				main(void)
{
	t_msh		data;

	sigint_handler();
	initialize_msh(&data);
	environ = setup_environ(&data); // MALLOC
	increment_level();
	while (1)
	{
		display_prompt();
		data.line = get_input(); // MALLOC
		if (data.line)
		{
			if (*(data.line))
				minishell(&data);
			ft_strdel(&(data.line));
		}
		else
			ft_putchar('\n');
	}
	return (0);
}
