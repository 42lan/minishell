/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_environ_rows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 21:44:55 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/31 03:50:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					total_environ_rows(void)
{
	int				i;
	extern char		**environ;

	i = 0;
	while (environ[i])
		i++;
	return (i);
}
