/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:25:08 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/08 20:52:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	check_access() function performs the accessibility of the file named by the
** 	realpath. Firstly it performs existence test (F_OK), then execute/search
** 	permission test (X_OK).
**
** RETURN VALUES
**	Upon successful completion, the value 1 is returned otherwise the value 0.
*/

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
