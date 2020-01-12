/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslan <aslan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 07:07:05 by aslan             #+#    #+#             */
/*   Updated: 2020/01/12 05:44:20 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define CONSERVE 0
# define OVERWRITE 1

# define E_ACCES "minishell: permission denied: "
# define E_ENOENT "minishell: no such file or directory: "
# define E_UNSETHOME "minishell: cd: HOME not set."
# define E_ENOFOUND ": command not found"
# define E_ISDIR ": is a directory"
# define E_FEWARGS "unsetenv: Too few arguments."
# define E_MANYARGS "builtins: Too many arguments."
# define E_BEGIN "setenv: Variable name must begin with a letter."
# define E_ALNUM "setenv: Variable name must contain alphanumeric characters."
# define E_GETCWD "pwd: error retrieving current directory"
# define E_NUMARGREQ "minishell: exit: numeric argument required"

#endif
