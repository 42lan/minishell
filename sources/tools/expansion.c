/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:24:53 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/17 03:49:10 by aslan            ###   ########.fr       */
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
	if (!(home = ft_getenv("HOME")))
		return ;
	i = ft_strchr_index(*command, '~');
	newstr = ft_strnew(ft_strlen(*command) - 1 + ft_strlen(home));
	newstr = ft_strncpy(newstr, *command, i);
	newstr = ft_strcat(newstr, home);
	newstr = ft_strcat(newstr, *command + i + 1);
	*command = newstr;
	ft_strdel(&tmp);
}

static void		expand_dollar_helper(char **command, char **new_command, int i)
{
	char		*tmp;
	char		*value;
	char		*variable;

	variable = ft_strsub(*command, 0, i);
	value = ft_getenv(variable);
	if (value)
	{
		tmp = *new_command;
		*new_command = ft_strjoin(*new_command, value);
		ft_strdel(&tmp);
		tmp = *new_command;
		*new_command = ft_strjoin(*new_command, *command + i);
		ft_strdel(&tmp);
	}
	else
	{
		**new_command = '\0';
		ft_printf("%s: Undefined variable\n", variable);
	}
	ft_strdel(&variable);
}

static void		expand_dollar(char **command)
{
	int			i;
	char		*tmp;
	char		*new_command;

	i = 0;
	tmp = *command;
	new_command = ft_strsub(*command, 0, ft_strclen(*command, '$'));
	*command += ft_strclen(*command, '$') + 1;
	while ((*command)[i] && (ft_isalpha((*command)[i]) || (*command)[i] == '_'))
		i++;
	expand_dollar_helper(command, &new_command, i);
	*command = new_command;
	ft_strdel(&tmp);
}

void			expand_symbols(char **command)
{
	(void)expand_dollar;
	(void)expand_tilde;
	int			i;

	i = -1;
	while((*command)[++i])
	{
		if ((*command)[i] == '~')
			expand_tilde(command);
		if ((*command)[i] == '$' && (*command)[i + 1])
			expand_dollar(command);
	}
}
