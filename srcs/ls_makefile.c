/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_makefile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 02:46:30 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/19 11:34:26 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct dirent	*ft_makedirent(char *path)
{
	struct dirent	*dirent;

	if (!(dirent = malloc(sizeof(struct dirent))))
		return (NULL);
	ft_strcpy(dirent->d_name, path);
	return (dirent);
}

t_file			*ft_makefile_commit(char *path, struct dirent *dirent,
		struct stat *buff_stat)
{
	t_file		*file;

	file = malloc(sizeof(*file));
	file->path = ft_strdup(path);
	file->dirent = *dirent;
	file->stat = *buff_stat;
	file->xattrs = NULL;
	file->xattrs_buffsize = 0;
	get_xattr_names(file);
	ft_get_acls(file);
	free(buff_stat);
	return (file);
}

t_file			*ft_makefile(char *path, struct dirent *dirent)
{
	struct stat	*buff_stat;
	char		*str;

	if (dirent == NULL)
	{
		dirent = ft_makedirent(path);
		path = "";
	}
	if (!(buff_stat = malloc(sizeof(struct stat))))
		return (NULL);
	str = make_path(path, dirent->d_name);
	errno = 0;
	if (g_toptions[o_L])
		stat(str, buff_stat);
	else
		lstat(str, buff_stat);
	if (ft_check_errno(dirent->d_name))
		return (NULL);
	free(str);
	return (ft_makefile_commit(path, dirent, buff_stat));
}

t_list			*ft_makefilelist(char *path, DIR *dir)
{
	struct dirent	*dirent;
	t_list			*files;
	t_list			*ptr;
	t_file			*file;

	ptr = NULL;
	files = NULL;
	while (1)
	{
		dirent = readdir(dir);
		if (dirent == NULL)
			break ;
		if ((file = ft_makefile(path, dirent)) != NULL)
		{
			ft_lstconstruct(&files, &ptr, ft_lstnew(file,
			sizeof(t_file)));
			free(file);
		}
	}
	return (files);
}

t_list			*ft_makefilelist_d(t_list *dirs)
{
	t_list			*files;
	t_list			*ptr;
	t_file			*file;

	files = NULL;
	ptr = NULL;
	while (dirs != NULL)
	{
		if ((file = ft_makefile(dirs->content, NULL)) != NULL)
		{
			ft_lstconstruct(&files, &ptr, ft_lstnew(file,
			sizeof(t_file)));
		}
		dirs = dirs->next;
	}
	return (files);
}
