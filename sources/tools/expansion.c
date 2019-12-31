/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:24:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/31 04:46:37 by amalsago         ###   ########.fr       */
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

static void		expand_dollar_helper(char **variables, char **newstr)
{
	char		*value;
	char		*tmp_str;
	char		*tmp_var;

	while (*variables)
	{
		tmp_var = *variables;
		*variables = ft_strtrim(*variables);
		ft_strdel(&tmp_var);
		if ((value = ft_getenv(*variables)))
		{
			tmp_str = *newstr;
			*newstr = ft_strjoin_sep(*newstr, value, " ");
			ft_strdel(&tmp_str);
		}
		else
			ft_printf("%s: Undefined variable\n", *variables);
		variables++;
	}
}

static void		expand_dollar(char **command)
{
	char		*newstr;
	char		**variables;

	variables = ft_strsplit(*command + ft_strcspn(*command, "$"), '$');
	newstr = ft_strsub(*command, 0, ft_strcspn(*command, "$"));
	expand_dollar_helper(variables, &newstr);
	ft_strarraydel(&variables);
	ft_strdel(command);
	*command = newstr;
}

void			expand_symbols(char **command)
{
	int			i;

	i = -1;
	while ((*command)[++i])
	{
		if ((*command)[i] == '~' && (*command)[i - 1] != '"')
			expand_tilde(command);
		else if ((*command)[i] == '$' && (*command)[i + 1])
			expand_dollar(command);
	}
}
