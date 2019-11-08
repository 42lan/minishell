/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:10:52 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/08 19:05:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int			builtin_cd(const char *line);
int			builtin_echo(const char *line);
int			builtin_env(void);
void		builtin_exit(void);
int			builtin_setenv(const char *line);
//void	builtin_which(const char *line);

static char *g_builtins[] = {
	"cd",
	"echo",
	"env",
	"exit",
	"setenv",
	"unsetenv",
};

#endif
