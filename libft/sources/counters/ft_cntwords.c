/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:18:21 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:49:57 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Computes and returns the number of words in a given string s separated by c.
*/

int			ft_cntwords(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (!ft_isseparator(s[i], c))
		{
			words++;
			while (!ft_isseparator(s[i], c) && s[i] != '\0')
				i++;
		}
		i++;
	}
	return (words);
}
