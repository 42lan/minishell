/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:36:32 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/08 08:25:19 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes a given error message to the standard error file descriptor followed
** by a newline. If error is empty or NULL writes: Unknown error message.
*/

int		ft_perror(const char *s)
{
	if (s && *s)
		ft_putstr_fd(s, STDERR_FILENO);
	else
		ft_putstr_fd("Unknown error", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (1);
}
