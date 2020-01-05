/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:39:59 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/05 21:56:50 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
		ft_printf("%s\n", cwd);
	else
	{
		ft_perror("pwd: error retrieving current directory");
		ft_perror("getcwd: cannot access parent directories");
	}
	ft_strdel(&cwd);
	return (0);
}
