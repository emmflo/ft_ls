/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:44:29 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/15 10:25:46 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_permission_user(char *permissions, struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_IRUSR) != 0)
		permissions[0] = 'r';
	if ((buff_stat->st_mode & S_IWUSR) != 0)
		permissions[1] = 'w';
	if ((buff_stat->st_mode & S_IXUSR) != 0)
		if ((buff_stat->st_mode & S_ISUID) != 0)
			permissions[2] = 's';
		else
			permissions[2] = 'x';
	else if ((buff_stat->st_mode & S_ISUID) != 0)
		permissions[2] = 'S';
}

void	ft_permission_group(char *permissions, struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_IRGRP) != 0)
		permissions[3] = 'r';
	if ((buff_stat->st_mode & S_IWGRP) != 0)
		permissions[4] = 'w';
	if ((buff_stat->st_mode & S_IXGRP) != 0)
		if ((buff_stat->st_mode & S_ISGID) != 0)
			permissions[5] = 's';
		else
			permissions[5] = 'x';
	else if ((buff_stat->st_mode & S_ISGID) != 0)
		permissions[5] = 'S';
}

void	ft_permission_other(char *permissions, struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_IROTH) != 0)
		permissions[6] = 'r';
	if ((buff_stat->st_mode & S_IWOTH) != 0)
		permissions[7] = 'w';
	if ((buff_stat->st_mode & S_IXOTH) != 0)
		if ((buff_stat->st_mode & S_ISVTX) != 0)
			permissions[8] = 't';
		else
			permissions[8] = 'x';
	else if ((buff_stat->st_mode & S_ISVTX) != 0)
		permissions[8] = 'T';
}

void	ft_permission_extra(char *permissions, t_file *file)
{
	if (file->xattrs_buffsize > 0)
		permissions[9] = '@';
	else if (file->acl != NULL && ft_type_to_char(&(file->stat)) != 'l')
		permissions[9] = '+';
}
