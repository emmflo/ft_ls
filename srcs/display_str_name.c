/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:04:52 by eflorenz          #+#    #+#             */
/*   Updated: 2017/09/04 18:30:02 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <ctype.h>

char	*ft_make_name(t_list *files)
{
	char	*name;

	name = ft_str_name_(files);
	return (name);
}

char	*ft_str_name_(t_list *files)
{
	char	*name;

	check_malloc(name = ft_strnew(
		ft_strlen(((t_file*)files->content)->dirent.d_name)));
	ft_strcpy(name, ((t_file*)files->content)->dirent.d_name);
	return (name);
}

char	*ft_str_name(t_list *files, t_column_sizes *cs)
{
	char		*str;
	char		*name;
	struct stat	*buff_stat;

	buff_stat = &((t_file*)files->content)->stat;
	name = ft_make_name(files);
	check_malloc(str = ft_strnew(ft_len_name(name, cs)
			+ g_toptions[o_F] + g_toptions[o_p] + 20 * g_toptions[o_G]));
	str[0] = '\0';
	ft_color_name_start(str, buff_stat);
	ft_strcat(str, name);
	if (name != NULL)
		ft_strdel(&name);
	ft_color_name_end(str);
	if (g_toptions[o_F])
	{
		str[ft_strlen(str) + 1] = '\0';
		str[ft_strlen(str)] = ft_f__char(buff_stat);
	}
	else if (g_toptions[o_p] && (buff_stat->st_mode & S_IFMT) == S_IFDIR)
	{
		str[ft_strlen(str) + 1] = '\0';
		ft_strcat(str, "/");
	}
	return (str);
}
