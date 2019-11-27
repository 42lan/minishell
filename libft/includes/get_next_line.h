/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:24:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/27 15:55:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE_GNL 32
# ifndef OPEN_MAX
#  define OPEN_MAX 2048
# endif

# include <unistd.h>
# include <limits.h>
# include <string.h>
# include "libft.h"

int		get_next_line(const int fd, char **line);

#endif
