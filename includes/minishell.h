/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:44:42 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/14 14:27:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtins.h"
# include "colors.h"
# include "system_libraries.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

char	*get_input(void);
char	**parse_input(const char *line);
void	write_history(const char *line);

void	expand_symbols(char **command);
char	*find_executable(const char *executable);
int		check_access(const char *realpath);
int		is_builtin(const char *command);
int		execute(const char *line);
void	execute_builtin(const char *command, const char *line);
int		execute_command(char **command);

void	print_eacces(const char *filename);
void	print_enoent(const char *filename);
void	print_enofound(const char *filename);

void	display_prompt(void);
void	clear_console(void);
void	print_commands(char **commands);
void	ft_arraydel(char **array);

char	**duplicate_environ(void);
int		total_environ_rows(void);
#endif
