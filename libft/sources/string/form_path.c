/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:59:17 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/08 11:02:16 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*form_path(const char *dirname, char const *basename)
{
	char	*path;

	if (!dirname || !basename)
		return (NULL);
	if (!(path = ft_strnew(ft_strlen(dirname) + 1 + ft_strlen(basename))))
		return (NULL);
	path = ft_strcpy(path, dirname);
	if (!ft_strequ(dirname, "/"))
		path = ft_strcat(path, "/");
	path = ft_strcat(path, basename);
	return (path);
}
