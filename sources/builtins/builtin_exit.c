/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:36:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/26 15:34:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exit(t_msh *data)
{
	ft_strdel(&(data->line));
	ft_strdel(&(data->history_file));
	ft_strarraydel(&(data->argv));
	ft_strarraydel(&(data->environ));
	ft_strarraydel(&(data->commands));
	data = NULL;
	exit(EXIT_SUCCESS);
}
