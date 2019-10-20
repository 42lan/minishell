/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_and_exit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:35:13 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/19 19:39:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_print_error_and_exit() performs normal termination of process.
**
** EXIT_FAILURE is the standard value for returning unsuccessful termination
** defined it stdlib.h.
*/

void	ft_print_error_and_exit(const char *error)
{
	ft_print_error(error);
	exit(EXIT_FAILURE);
}
