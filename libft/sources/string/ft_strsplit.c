/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 08:02:34 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/26 12:07:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns an array of “fresh” strings (all ending with ’\0’,
** including the array itself) obtained by splitings using the characterc as a
** delimiter. If the allocation fails the function returns NULL.
*/

static char			*ft_storeword(char const *s, char c)
{
	unsigned int	i;
	char			*word;

	i = -1;
	if (!(word = ft_strnew(ft_strclen(s, c))))
		return (NULL);
	while (s[++i] != '\0' && !(ft_isseparator(s[i], c)))
		word[i] = s[i];
	return (word);
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	words;
	char			**array;

	i = -1;
	if (!s || !*s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(array = (char **)ft_memalloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (*s != '\0')
	{
		if (!(ft_isseparator(*s, c)))
		{
			if (!(array[++i] = ft_storeword(s, c)))
			{
				ft_strarraydel(&array);
				return (NULL);
			}
			s += ft_strcspn(s, &c);
		}
		else
			s++;
	}
	return (array);
}
