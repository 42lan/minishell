/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:44:42 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/09 18:50:11 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "system_libraries.h"
# include "../libft/includes/libft.h"

void		display_prompt(char *envp[]);
void		clear_console(void);

#endif
