/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:44:42 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/02 15:46:23 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "system_libraries.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

typedef struct	s_msh
{
	char		*line;
	char		*history_file;
	char		**argv;
	char		**environ;
	char		**commands;
}				t_msh;

void			increment_level(void);

char			*get_input(void);
char			**parse_input(const char *line);
void			write_history(t_msh *data, const char *line);

void			expand_symbols(char **command);
char			*find_executable(const char *executable);
int				check_access(const char *realpath);
int				is_builtin(const char *command);
int				execute(t_msh *data, const char *line);
void			execute_builtin(t_msh *data, const char *command, const char *line);
int				execute_command(const char *realpath, char **command);

void			print_eacces(const char *filename);
void			print_enoent(const char *filename);
void			print_enofound(const char *filename);

void			display_prompt(void);
void			clear_console(void);
void			print_commands(char **commands);
void			ft_arraydel(char **array);

char			**setup_environ(t_msh *data);
int				total_environ_rows(void);

int				builtin_builtins(const char *args);
int				builtin_cd(const char *line);
int				builtin_echo(const char *line);
int				builtin_env(void);
void			builtin_exit(t_msh *data);
int				builtin_pwd(void);
int				builtin_setenv(const char *line);
int				ft_setenv(const char *name, const char *value, int overwrite);
int				ft_unsetenv(const char *name);

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
#endif
