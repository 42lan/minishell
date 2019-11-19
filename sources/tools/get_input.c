/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:29:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/17 18:45:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	get_input()
**
** RETURN VALUES
**	Upon successful completion, users entry is returned otherwise NULL.
*/

char		*get_input(void)
{
	char	*tmp;
	char	*input;

	input = NULL;
	if (get_next_line(0, &input) <= 0)
		if (!input)
			ft_strdel(&input);
	if (input != NULL)
	{
		tmp = input;
		if ((input = ft_strtrim(input)) == NULL)
			ft_strdel(&input);
		ft_strdel(&tmp);
	}
	return (input);
}
