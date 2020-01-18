/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:45:46 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/18 18:13:17 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	main() run infinite loop displaying prompt, getting input from user and
**	calling minishell() to execute received commands.
**
**	minishell() prepares execution of users input through parse_input().
**
**	nl_prompt() is called when SIGINT signal is received. The sequence of
**	characters "\b\b  \n" printed on STDOUT allows to remove  sign.
**
**	initialize_msh() initialize variables of t_msh stucture.
**
**	sigint_handler() handle SIGINT signal by calling signal().
**
**
** RETURN VALUES
**	Upon successful completion, the value 0 is returned.
*/

int					g_exit_status = 0;

static void			nl_prompt(int signum)
{
	(void)signum;
	ft_putstr("\b\b  \n");
	display_prompt();
}

static void			sigint_handler(void)
{
	signal(SIGINT, nl_prompt);
}

static void			initialize_msh(t_msh *data)
{
	data->line = NULL;
	data->history_file = NULL;
	data->argv = NULL;
	data->environ = NULL;
	data->commands = NULL;
}

static void			minishell(t_msh *data)
{
	int				i;

	i = -1;
	data->commands = parse_input(data->line);
	while (data->commands[++i])
	{
		write_history(data, data->commands[i]);
		if ((data->argv = ft_strsplit_spaces(data->commands[i])))
		{
			execute(data, data->commands[i]);
			ft_strarraydel(&data->argv);
		}
	}
	ft_strarraydel(&data->commands);
}

int					main(void)
{
	t_msh			data;
	extern char		**environ;

	sigint_handler();
	display_logtime();
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
		{
			ft_putstr("\b exit\n");
			builtin_exit(&data);
		}
	}
	return (0);
}
