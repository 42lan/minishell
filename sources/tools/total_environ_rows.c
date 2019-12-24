/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_environ_rows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 21:44:55 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/30 21:51:04 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

int				total_environ_rows(void)
{
	int			i;

	i = 0;
	while (environ[i])
		i++;
	return (i);
}
