/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:45:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/16 13:23:12 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	char	*command;

	if (argc > 1)
		command = argv[1];
	//clear_console();
	while (1)
	{
		display_prompt(envp);
		command = get_input();
		//parse_input(command);
		ft_printf("%s", command);
		ft_printf("\n");
	}
	ft_printf("minishell terminated\n");
	return (0);
}
