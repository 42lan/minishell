/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:36:27 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/05 07:05:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	int			value;
	char		*args;

	args = data->line + ft_strspn(data->line, "exit \t");
	value = ft_atoi(ft_strtok(args, " \t"));
	free_memory(data);
	exit(value);
}
