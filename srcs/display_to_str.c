/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 00:53:57 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/15 11:01:47 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_f__char(struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_IFMT) == S_IFDIR)
		return ('/');
	else if ((buff_stat->st_mode & S_IFMT) == S_IFREG &&
			(((buff_stat->st_mode & S_IXUSR) != 0) ||
			((buff_stat->st_mode & S_IXGRP) != 0) ||
			((buff_stat->st_mode & S_IXOTH) != 0)))
		return ('*');
	else if ((buff_stat->st_mode & S_IFMT) == S_IFLNK)
		return ('@');
	else if ((buff_stat->st_mode & S_IFMT) == S_IFSOCK)
		return ('=');
	else if ((buff_stat->st_mode & S_IFMT) == S_IFWHT)
		return ('%');
	else if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
		return ('|');
	else
		return ('\0');
}

char	ft_type_to_char(struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	if ((buff_stat->st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	if ((buff_stat->st_mode & S_IFMT) == S_IFREG)
		return ('-');
	if ((buff_stat->st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	if ((buff_stat->st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	if ((buff_stat->st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	return ('-');
}

char	*link_to_str(char *path, struct stat *buff_stat)
{
	char			*str;
	int				size;
	int				ret;

	size = buff_stat->st_size;
	check_malloc(str = ft_strnew(size));
	ret = readlink(path, str, size);
	if (ret == -1)
	{
		exit(EXIT_FAILURE);
	}
	str[ret] = '\0';
	return (str);
}
