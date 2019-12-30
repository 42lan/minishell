/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 04:35:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/30 04:39:16 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a “fresh” string endint with '\0', result of the
** concatenation of s1 and s2 separated by sep.
** If the allocation fails the function returns NULL.
*/

char		*ft_strjoin_sep(char const *s1, char const *s2, const char *sep)
{
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	if (!(new_str = ft_strnew(ft_strlen(s1) + ft_strlen(sep) + ft_strlen(s2))))
		return (NULL);
	new_str = ft_strcpy(new_str, s1);
	if (sep)
		new_str = ft_strcat(new_str, sep);
	new_str = ft_strcat(new_str, s2);
	return (new_str);
}
