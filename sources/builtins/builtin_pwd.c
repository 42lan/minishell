/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:39:59 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/28 17:42:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_pwd(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (cwd != NULL)
		ft_printf("%s\n", cwd);
	else
		ft_perror("minishell: getcwd() returned NULL in builtin_pwd()");
	ft_strdel(&cwd);
	return (0);
}
