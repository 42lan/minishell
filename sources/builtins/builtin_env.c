/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:02:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 14:07:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

void			builtin_env(void)
{
	int			i;

	i = -1;
	while (environ[++i])
		ft_printf("%s\n", environ[i]);
}
