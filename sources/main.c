/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:45:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 17:32:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	char		*line;

	if (argc > 1)
		line = argv[1];
	//clear_console();
	while (1)
	{
		display_prompt(envp);
		line = get_input();
		if (*line)
			write_history(line);
		parse_input(line);
		ft_printf("%s", line);
		ft_printf("\n");
	}
	ft_printf("minishell terminated\n");
	return (0);
}
