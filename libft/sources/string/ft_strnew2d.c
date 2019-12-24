/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:47:14 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/29 11:40:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strnew2d(size_t size)
{
	char	**str;

	if (!(str = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	return (str);
}
