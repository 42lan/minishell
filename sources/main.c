/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:45:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/14 16:35:05 by amalsago         ###   ########.fr       */
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

static void		minishell(t_msh *data)
{
	int			i;

	i = -1;
	write_history(data, data->line);
	data->commands = parse_input(data->line);
	while (data->commands[++i])
		if ((data->argv = ft_strsplit(data->commands[i], ' ')))
		{
			execute(data, data->commands[i]);
			ft_strarraydel(&data->argv);
		}
	ft_strarraydel(&data->commands);
}

void			initialize_msh(t_msh *data)
{
	data->line = NULL;
	data->history_file = NULL;
	data->argv = NULL;
	data->environ = NULL;
	data->commands = NULL;
}

int				main(void)
{
	t_msh		data;

	sigint_handler();
	initialize_msh(&data);
	environ = setup_environ(&data);
	increment_level();
	while (1)
	{
		display_prompt();
		data.line = get_input();
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
