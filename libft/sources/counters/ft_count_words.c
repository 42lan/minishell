/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:18:21 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/17 13:49:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Computes and returns the number of words in a given string s separated by c.
*/

int			ft_count_words(char const *s, char c)
{
	int		i;
	int		words;

	(void)c;
	i = -1;
	words = 0;
	if (!s || !*s)
		return (0);
	while (s[++i])
		if (!ft_isseparator(s[i], c))
		{
			++words;
			while (!ft_isseparator(s[++i], c))
				if (s[i + 1] == '\0')
					return (words);
		}
	return (words);
}
