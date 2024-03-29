/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:44:23 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/30 02:17:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	Collection of function displaying error messages.
**
** RETURN VALUES
**	This functions does not return a value.
*/

void		print_eacces(const char *filename)
{
	char	*error;

	error = ft_strjoin("minishell: permission denied: ", filename);
	ft_perror(error);
	ft_strdel(&error);
}

void		print_enoent(const char *filename)
{
	char	*error;

	error = ft_strjoin("minishell: no such file or directory: ", filename);
	ft_perror(error);
	ft_strdel(&error);
}

void		print_enofound(const char *filename)
{
	char	*tmp;
	char	*error;

	error = ft_strjoin("minishell: ", filename);
	tmp = error;
	error = ft_strjoin(error, ": command not found");
	ft_perror(error);
	ft_strdel(&tmp);
	ft_strdel(&error);
}

void		print_isdir(const char *filename)
{
	char	*tmp;
	char	*error;

	error = ft_strjoin("minishell: ", filename);
	tmp = error;
	error = ft_strjoin(error, ": is a directory");
	ft_perror(error);
	ft_strdel(&tmp);
	ft_strdel(&error);
}
