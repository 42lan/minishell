/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:25:08 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/29 19:38:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_access(const char *realpath)
{
	if (access(realpath, F_OK) != 0)
	{
		ft_perror("minishell: no such file or directory: ");
		ft_perror(realpath);
		return (0);
	}
	if (access(realpath, X_OK) != 0)
	{
		ft_perror("minishell: permission denied: ");
		ft_perror(realpath);
		return (0);
	}
	return (1);
}
