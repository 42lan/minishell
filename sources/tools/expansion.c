/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:24:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/30 05:35:45 by amalsago         ###   ########.fr       */
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

static int		expand_dollar_helper(char **variables, char **newstr)
{
	char		*value;
	char		*tmp_str;
	char		*tmp_var;

	while (*variables)
	{
		tmp_var = *variables;
		*variables = ft_strtrim(*variables); // MALLOC
		ft_strdel(&tmp_var);
		if ((value = ft_getenv(*variables)))
		{
			tmp_str = *newstr;
			*newstr = ft_strjoin_sep(*newstr, value, " "); // MALLOC
			ft_strdel(&tmp_str);
		}
		else
		{
			ft_printf("%s: Undefined variable\n", *variables);
			return (0);
		}
		variables++;
	}
	return (1);
}

static void		expand_dollar(char **command)
{
	char		*newstr;
	char		**variables;

	variables = ft_strsplit(*command + ft_strcspn(*command, "$"), '$'); // MALLOC
	newstr = ft_strsub(*command, 0, ft_strcspn(*command, "$")); // MALLOC
	if ((expand_dollar_helper(variables, &newstr)) == 1)
	{
		ft_strdel(command);
		*command = newstr;
	}
	else
		ft_strdel(&newstr);
	ft_strarraydel(&variables);
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
