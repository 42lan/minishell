/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:15:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/24 01:57:54 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a copy of the string given as argument without
** whitespaces at the beginning or at the end of the string. Will be considered
** as whitespaces the following characters ’ ’, ’\n' and ’\t’. If s has no
** whitespaces at the beginning or at the end, the function returns a copy of s.
** If the allocation fails the function returns NULL.
*/

char		*ft_strctrim(char const *s, char c)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (ft_isseparator(s[i], c))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	j = ft_strlen(s) - 1;
	while (ft_isseparator(s[j], c))
		j--;
	if (!(new_str = ft_strsub(s, i, j - i + 1)))
		return (NULL);
	return (new_str);
}
