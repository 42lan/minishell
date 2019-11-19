/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:10:52 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/17 11:20:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int				builtin_builtins(const char *args);
int				builtin_cd(const char *line);
int				builtin_echo(const char *line);
int				builtin_env(void);
void			builtin_exit(void);
int				builtin_setenv(const char *line);
int				ft_setenv(const char *name, const char *value, int overwrite);
int				ft_unsetenv(const char *name);

static char		*g_builtins[] = {
	"builtins",
	"cd",
	"echo",
	"env",
	"exit",
	"setenv",
	"unsetenv",
	0
};

#endif
