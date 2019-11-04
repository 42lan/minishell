/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:32:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 18:57:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		builtin_setenv(const char *line)
{
	char	*key;
	char	*value;
	char	*string;
	//char	*environ_var;

	string = ft_strtrim(line + 6);
	key = ft_strtok(string, "=");
	value = key + ft_strlen(key) + 1; //value = ft_strtok(NULL, "=");
	ft_printf("|%s|\n", string);
	ft_printf("[%s]=[%s]\n", key, value);
	free(string);
}
