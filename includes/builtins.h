/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:10:52 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 16:26:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	builtin_echo(const char *line);
void	builtin_env(void);
void	builtin_exit(void);

static char *g_builtins[] = {
	"cd",
	"echo",
	"env",
	"exit",
	"setenv",
	"unsetenv",
};

#endif
