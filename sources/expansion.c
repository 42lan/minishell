/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:24:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/07 19:01:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		expand_tilde(char **command)
{
	int			i;
	char		*tmp;
	char		*home;
	char		*newstr;

	tmp = *command;
	home = ft_getenv("HOME");
	i = ft_strchr_index(*command, '~');
	newstr = ft_strnew(ft_strlen(*command) - 1 + ft_strlen(home));
	newstr = ft_strncpy(newstr, *command, i);
	newstr = ft_strcat(newstr, home);
	newstr = ft_strcat(newstr, *command + i + 1);
	*command = newstr;
	ft_strdel(&tmp);
}

static void		expand_dollar(char **command)
{
	int			i;
	char		*tmp;
	char		*value;
	char		*newstr;

	i = -1;
	newstr = NULL;
	tmp = *command;
	while ((*command)[++i])
		if ((*command)[i] == '$')
		{
			value = ft_getenv(&(*command)[i] + 1);
			newstr = ft_strnew(i + ft_strlen(value));
			newstr = ft_strncpy(newstr, *command, i);
			newstr = ft_strcat(newstr, value);
			break ;
		}
	*command = newstr;
	ft_strdel(&tmp);
}

void			expand_symbols(char **command)
{
	int			i;

	i = -1;
	while ((*command)[++i])
	{
		if ((*command)[i] == '~' && (*command)[i - 1] != '"')
			expand_tilde(command);
		else if ((*command)[i] == '$')
			expand_dollar(command);
	}
}
