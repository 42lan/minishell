/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:36:27 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/18 18:13:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_exit() function terminates a process after performing memory clean.
**	It also returns a global_exit_status value or can be precised as argument.
*/

extern int		g_exit_status;

static void		free_memory(t_msh *data)
{
	ft_strdel(&(data->line));
	ft_strdel(&(data->history_file));
	ft_strarraydel(&(data->argv));
	ft_strarraydel(&(data->environ));
	ft_strarraydel(&(data->commands));
	data = NULL;
}

void			builtin_exit(t_msh *data)
{
	int			i;
	char		*args;

	i = -1;
	if (data->line)
	{
		args = data->line + ft_strspn(data->line, "exit \t");
		if (*args)
		{
			while (args[++i])
				if (!ft_isdigit(args[i]))
				{
					ft_perror(E_NUMARGREQ);
					g_exit_status = 255;
					break ;
				}
			if (g_exit_status != 255)
				g_exit_status = ft_atoi(ft_strtok(args, " \t"));
		}
	}
	free_memory(data);
	exit(g_exit_status);
}
