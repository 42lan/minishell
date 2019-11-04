/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:36:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 14:00:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
int		builtin_exit(void)
{
	return (EXIT_SUCCESS);
}
*/

void	builtin_exit(void)
{
	exit(EXIT_SUCCESS);
}
