/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:39:59 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/17 07:10:22 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_pwd() prints the name of current working directory.
*/

extern int		g_exit_status;

int				builtin_pwd(void)
{
	char		*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (g_exit_status = ft_perror(E_GETCWD));
	ft_printf("%s\n", cwd);
	ft_strdel(&cwd);
	return (0);
}
