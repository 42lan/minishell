/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:21:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/27 11:21:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_arraydel(char **array)
{
	int		i;

	i = -1;
	if (array && *array)
	{
		while (array[++i])
			ft_strdel(&array[i]);
		free(array);
		array = NULL;
	}
}
