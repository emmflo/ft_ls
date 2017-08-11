/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:30:45 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:30:57 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_color_dir(struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_IWOTH) != 0)
	{
		if ((buff_stat->st_mode & S_ISVTX) != 0)
			return (ft_make_color_str(9));
		else
			return (ft_make_color_str(10));
	}
	else
		return (ft_make_color_str(0));
}

char	*ft_get_color_reg_file(struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_ISUID) != 0)
		return (ft_make_color_str(7));
	else if ((buff_stat->st_mode & S_ISGID) != 0)
		return (ft_make_color_str(8));
	else
		return (ft_make_color_str(4));
}

char	*ft_get_color(struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_IFMT) == S_IFDIR)
		return (ft_get_color_dir(buff_stat));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFLNK)
		return (ft_make_color_str(1));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFSOCK)
		return (ft_make_color_str(2));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
		return (ft_make_color_str(3));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFREG &&
			(buff_stat->st_mode & S_IXUSR) != 0)
		return (ft_get_color_reg_file(buff_stat));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
		return (ft_make_color_str(5));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFCHR)
		return (ft_make_color_str(6));
	else
		return (ft_strdup("\x1b[39m\x1b[49m"));
}
