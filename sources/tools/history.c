/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:06:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/23 05:23:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				write_history(t_msh *data, const char *line)
{
	char			*home_dir;
	char			*filename;
	int				oflag;
	int				mode;
	int				fd;

	home_dir = NULL;
	filename = ".minishell_history";
	oflag = O_RDWR | O_APPEND | O_CREAT;
	mode = S_IRUSR | S_IWUSR;
	if (!data->history_file)
		data->history_file = ((home_dir = ft_getenv("HOME")))
							? form_path(home_dir, filename) : filename;
	if ((fd = open(data->history_file, oflag, mode)) < 0)
		ft_perror("minishell: open() failed in write_history()");
	else
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		close(fd);
	}
}
