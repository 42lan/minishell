/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:06:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/02 19:02:23 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		write_history(const char *line)
{
	int		fd;
	int		mode;
	int		oflag;

	mode = S_IRUSR | S_IWUSR;
	oflag = O_RDWR | O_APPEND | O_CREAT;
	if ((fd = open(".minishell_history", oflag, mode)) < 0)
		ft_perror("minishell: open() failed in write_history()");
	else
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		close(fd);
	}
}
