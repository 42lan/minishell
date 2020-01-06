/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:06:56 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/01 06:19:11 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		set_history_file(t_msh *data)
{
	char		*cwd;
	char		*filename;
	char		*home_dir;

	home_dir = NULL;
	filename = ".minishell_history";
	if ((home_dir = ft_getenv("HOME")))
		data->history_file = form_path(home_dir, filename);
	else
	{
		cwd = getcwd(NULL, 0);
		data->history_file = form_path(cwd, filename);
		ft_strdel(&cwd);
	}
}

void			write_history(t_msh *data, const char *line)
{
	int			fd;
	int			mode;
	int			oflag;

	mode = S_IRUSR | S_IWUSR;
	oflag = O_RDWR | O_APPEND | O_CREAT;
	if (!data->history_file)
		set_history_file(data);
	if ((fd = open(data->history_file, oflag, mode)) > 0)
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		close(fd);
	}
}
