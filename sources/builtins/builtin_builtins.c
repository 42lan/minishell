/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:40:55 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/08 09:01:44 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	builtin_builtins() prints minishell builtin commands that can be executed
**	within the running minishell's process.
**
** RETURN VALUES
**	Upon successful completion, the value 0 is returned otherwise the value 1.
*/

static size_t		get_max_len(void)
{
	size_t			i;
	size_t			len;
	size_t			max_len;

	i = -1;
	max_len = 0;
	while (g_builtins[++i])
	{
		len = ft_strlen(g_builtins[i]);
		if (len > max_len)
			max_len = len;
	}
	return (max_len);
}

static size_t		get_per_row(size_t max_name_len)
{
	size_t			per_row;
	struct winsize	terminal;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &terminal);
	per_row = (terminal.ws_col / max_name_len) - 1;
	return ((per_row < 1) ? 1 : per_row);
}

static int			check_many_arguments(const char *args)
{
	int				i;

	i = -1;
	while (ft_iswhitespace(args[++i]))
		if (args[i])
			return (1);
	return (0);
}

int					builtin_builtins(const char *args)
{
	size_t			i;
	size_t			width;
	size_t			per_row;
	size_t			max_name_len;

	i = -1;
	max_name_len = get_max_len();
	per_row = get_per_row(max_name_len + 5);
	if (check_many_arguments(args))
		return (ft_perror(E_MANYARGS));
	while (g_builtins[++i])
	{
		if (i == per_row)
			ft_putchar('\n');
		width = max_name_len + 5;
		ft_printf("%-*s", width, g_builtins[i]);
	}
	ft_putchar('\n');
	return (0);
}
