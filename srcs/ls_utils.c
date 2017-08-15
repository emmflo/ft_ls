/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:21:45 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/15 05:43:18 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*make_path(char *path, char *name)
{
	char	*str;
	int		offset;
	int		path_len;

	offset = 0;
	path_len = ft_strlen(path);
	if (path_len > 0 && path[path_len - 1] != '/')
		offset = 1;
	str = ft_strnew(path_len + ft_strlen(name) + offset);
	ft_strcat(str, path);
	if (offset)
		ft_strcat(str, "/");
	ft_strcat(str, name);
	return (str);
}

char	*ft_newg_toptions(void)
{
	char	*toptions;
	int		i;

	i = 0;
	toptions = ft_strnew(NB_OPTIONS);
	while (i < NB_OPTIONS)
		toptions[i++] = 0;
	return (toptions);
}

void	ft_deldir(void *str, size_t size)
{
	str = NULL;
	(void)size;
}
