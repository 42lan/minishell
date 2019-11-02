/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:29:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/02 19:01:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_input(void)
{
	char	*tmp;
	char	*input;

	if (get_next_line(0, &input) <= 0)
	{
		ft_strdel(&input);
		ft_perror("minishell: GNL call returned value < 1 in get_input()");
	}
	if (*input)
	{
		tmp = input;
		if ((input = ft_strtrim(input)) == NULL)
		{
			ft_strdel(&input);
			ft_perror("minishell: ft_strtrim() failed in get_input()");
		}
		ft_strdel(&tmp);
	}
	return (input);
}
