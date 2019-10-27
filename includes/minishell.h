/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:44:42 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/27 15:56:03 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "system_libraries.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

void		display_prompt(void);
void		clear_console(void);
char		*get_input(void);
char		**parse_input(const char *line);
void		write_history(const char *line);
char		*ft_getenv(const char *name);
void		print_commands(char **commands);
void		ft_arraydel(char **array);
int			execute_command(const char *command);
char		*find_executable(const char *executable);


#endif
