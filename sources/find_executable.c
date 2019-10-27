/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:55:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/27 15:56:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*find_executable(const char *executable)
{
	char	*realpath;
	char	*directory;
	char	*directories;

	realpath = NULL;
	directories = ft_getenv("PATH");
	directory = ft_strtok(directories, ":");
	while (directory)
	{
		directory = ft_strtok(NULL, ":");
		realpath = ft_realpath(directory, executable);
		if (access(realpath, F_OK) == 0)
			break ;
	}
	return (realpath);
}
