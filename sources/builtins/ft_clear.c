/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:19:32 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/31 03:31:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Escape sequences start with ESC (033/1b/27)
** CSI (Control Sequence Introducer): ESC + [
** CUP (Cursor position): CSIn;mH moves the cursor to row n and column m
** Clear console screen on ANSI terminals using escape characters
*/

void	ft_clear(void)
{
	ft_putstr("\e[1;1H\e[2J");
}
