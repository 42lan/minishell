/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:25:08 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/02 19:06:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_access(const char *realpath)
{
	char	*error;

	if (access(realpath, F_OK) != 0)
	{
		error = ft_strjoin("minishell: no such file or directory: ", realpath);
		ft_perror(error);
		ft_strdel(&error);
		return (0);
	}
	if (access(realpath, X_OK) != 0)
	{
		error = ft_strjoin("minishell: permission denied: ", realpath);
		ft_perror(error);
		ft_strdel(&error);
		return (0);
	}
	return (1);
}
