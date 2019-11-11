/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:06:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/11 14:32:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				write_history(const char *line)
{
	int				fd;
	int				mode;
	int				oflag;
	static char		*history_file;

	mode = S_IRUSR | S_IWUSR;
	oflag = O_RDWR | O_APPEND | O_CREAT;
	if (!history_file)
		history_file = form_path(ft_getenv("HOME"), ".minishell_history");
	if ((fd = open(history_file, oflag, mode)) < 0)
		ft_perror("minishell: open() failed in write_history()");
	else
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		close(fd);
	}
}
