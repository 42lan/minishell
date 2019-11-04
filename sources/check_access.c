/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:25:08 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 10:49:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_access(const char *realpath)
{
	if (access(realpath, F_OK) != 0)
	{
		print_enoent(realpath);
		return (0);
	}
	if (access(realpath, X_OK) != 0)
	{
		print_eacces(realpath);
		return (0);
	}
	return (1);
}
