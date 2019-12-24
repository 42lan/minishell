/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:30:26 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/01 14:20:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates sufficient memory for a copy of the string s1, does the copy, and
** returns a pointer to it. The pointer may subsequently be used as an argument
** to the function free(3).
** If insufficient memory is available, NULL is returned.
*/

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	if (!(s2 = ft_strnew(ft_strlen(s1))))
		return (NULL);
	while (*s1)
	{
		s2[i] = *s1++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
