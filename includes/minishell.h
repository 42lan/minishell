/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:44:42 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/18 18:13:12 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "colors.h"
# include "defines.h"
# include "system_libraries.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

static char		*g_builtins[] = {
	"builtins",
	"cd",
	"echo",
	"env",
	"exit",
	"pwd",
	"setenv",
	"unsetenv",
	0
};

typedef struct	s_msh
{
	char		*line;
	char		*history_file;
	char		**argv;
	char		**environ;
	char		**commands;
}				t_msh;

int				check_access(const char *realpath);
void			expand_symbols(char **command);
char			*get_input(void);
void			increment_level(void);
char			**parse_input(const char *line);
char			**setup_environ(t_msh *data);
int				total_environ_rows(void);
void			write_history(t_msh *data, const char *line);
int				builtin_builtins(const char *args);
int				builtin_cd(t_msh *data, const char *line);
int				builtin_echo(const char *line);
int				builtin_env(void);
void			builtin_exit(t_msh *data);
int				builtin_pwd(void);
int				builtin_setenv(t_msh *data, const char *line);
void			builtin_unsetenv(const char *line);
void			ft_clear(void);
int				ft_clearenv(void);
int				ft_setenv(const char *name, const char *value, int overwrite);
int				ft_unsetenv(const char *name);
int				execute(t_msh *data, const char *line);
void			execute_builtin(t_msh *data, const char *command,
				const char *line);
int				execute_command(const char *realpath, char **command);
char			*find_executable(const char *executable);
void			display_logtime(void);
void			display_prompt(void);
void			print_commands(char **commands);
void			print_eacces(const char *filename);
void			print_enoent(const char *filename);
void			print_enofound(const char *filename);
void			print_isdir(const char *filename);
int				is_builtin(const char *command);
int				is_var_exist(const char *name);

#endif
