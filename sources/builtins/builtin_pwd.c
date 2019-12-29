/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:39:59 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/29 04:45:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0); // MALLOC
	if (cwd != NULL)
		ft_printf("%s\n", cwd);
	else
		ft_perror("pwd: .: Permission denied");
	ft_strdel(&cwd);
	return (0);
}
