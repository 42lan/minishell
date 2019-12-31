/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 06:10:17 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/31 03:13:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_storeword(char const *s)
{
	unsigned int	i;
	int				c;
	char			*word;

	i = -1;
	c = ft_strcspn(s, "\t\n\v\f\r ");
	if (!(word = ft_strnew(c)))
		return (NULL);
	while (s[++i] != '\0' && !(ft_isspace(s[i])))
		word[i] = s[i];
	return (word);
}

int					ft_count_words_spaces(char const *s)
{
	int				i;
	int				words;

	i = -1;
	words = 0;
	if (!s || !*s)
		return (0);
	while (s[++i])
		if (!ft_isspace(s[i]))
		{
			++words;
			while (s[i] && !ft_isspace(s[i]))
				++i;
			if (s[i] == '\0')
				break ;
		}
	return (words);
}

char				**ft_strsplit_spaces(char const *s)
{
	unsigned int	i;
	unsigned int	words;
	char			**array;

	i = -1;
	if (!s || !*s)
		return (NULL);
	words = ft_count_words_spaces(s);
	if (!(array = (char **)ft_memalloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (*s != '\0')
	{
		if (!(ft_isspace(*s)))
		{
			if (!(array[++i] = ft_storeword(s)))
			{
				ft_strarraydel(&array);
				return (NULL);
			}
			s += ft_strcspn(s, "\t\n\v\f\r ");
		}
		else
			s++;
	}
	return (array);
}
