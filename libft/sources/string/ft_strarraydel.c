/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraydel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:21:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/18 00:10:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes as a parameter the address of the array of strings that need to be 
** freed,  then sets its pointer to NULL.
*/

void		ft_strarraydel(char ***array_ptr)
{
	int		i;

	i = -1;
	if (array_ptr && *array_ptr)
	{
		while ((*array_ptr)[++i])
			ft_strdel(*array_ptr + i);
		if (*array_ptr && **array_ptr)
			free(*array_ptr);
		*array_ptr = NULL;
	}
}
