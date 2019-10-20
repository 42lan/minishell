/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:36:32 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 09:49:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes a given error message to the standard error file descriptor.
** If error is pointed to NULL writes Unknown error message.
*/

void	ft_print_error(const char *error)
{
	if (!error)
		ft_putstr_fd("Unknown error\n", STDERR_FILENO);
	else
		ft_putstr_fd(error, STDERR_FILENO);
}
