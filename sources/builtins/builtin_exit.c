/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:36:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/31 06:17:03 by amalsago         ###   ########.fr       */
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
	char		*trimmed;

	trimmed = ft_strtrim(data->line + ft_strspn(data->line, "exit"));
	value = ft_atoi(trimmed);
	ft_strdel(&trimmed);
	free_memory(data);
	exit(value < 0 ? EXIT_SUCCESS : value);
}
