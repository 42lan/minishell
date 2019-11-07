/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:24:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/07 16:25:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		expand_tilde(char **command)
{
	char		*tmp;
	char		*home;
	char		*newstr;

	tmp = *command;
	home = ft_getenv("HOME");
	newstr = ft_strnew(ft_strlen(*command) - 1 + ft_strlen(home));
	ft_strncpy(newstr, *command, ft_strchr_index(*command, '~'));
	ft_strcat(newstr, home);
	ft_strcat(newstr, *command + ft_strchr_index(*command, '~') + 1);
	*command = newstr;
	ft_strdel(&tmp);
}

void			expand_symbols(char **command)
{
	int			i;

	i = -1;
	while ((*command)[++i])
		if ((*command)[i] == '~')
			expand_tilde(command);
}
