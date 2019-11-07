/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:32:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/06 16:33:37 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

static int		total_rows(void)
{
	int			rows;

	rows = 0;
	while (environ[rows])
		rows++;
	return (rows);
}

int				ft_setenv(const char *name, const char *value, int rewrite)
{
	int			i;
	int			length;
	char		**new_environ;
	char		*to_add;

	i = -1;
	new_environ = ft_strnew2d(total_rows() + 1); // +1 for new var and NULL
	while (environ[++i])
		new_environ[i] = ft_strdup(environ[i]);
	length = ft_strlen(name) + ft_strlen(value);
	to_add = ft_strnew(length);
	(void)rewrite;
	ft_strcpy(to_add, name);
	ft_strcat(to_add, "=");
	ft_strcat(to_add, value);
	new_environ[i] = to_add;
	new_environ[i + 1] = NULL;
	environ = new_environ;
	i = -1;
	while (environ[++i])
		ft_printf(">>>%s\n", environ[i]);
	return (1);
}

void			builtin_setenv(const char *line)
{
	int			rewrite = 1;
	char		*name;
	char		*value;
	char		*new_env_var;

	new_env_var = ft_strtrim(line + 6);

	name = ft_strtok(new_env_var, "=");
	value = name + ft_strlen(name) + 1; //value = ft_strtok(NULL, "=");
	ft_printf("|%s|\n", new_env_var);
	ft_printf("[%s]=[%s]\n", name, value);
	
	ft_setenv(name, value, rewrite);


	/*
	ft_arraydel(environ)
	environ = new_environ;
	*/
	exit(EXIT_SUCCESS); // To terminate child process
}
