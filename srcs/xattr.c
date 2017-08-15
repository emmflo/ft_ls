/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xattr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:28:13 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/15 07:22:47 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
void	ft_delattr(void *content, size_t size)
{
	
}
*/

void	make_xattr_names(t_file *file, char *attr_names, t_list *attrs,
		char *path)
{
	ssize_t	i;
	ssize_t	offset;
	t_list	*ptr;
	t_xattr	*attr;

	i = 0;
	ptr = NULL;
	while (i < file->xattrs_buffsize)
	{
		if (!(attr = malloc(sizeof(t_xattr))))
			return ;
		attr->name = ft_strdup(&attr_names[i]);
		attr->size = getxattr(path, attr->name, NULL, 0, 0, XATTR_NOFOLLOW);
		if (!(attr->attr = malloc(attr->size)))
			return ;
		getxattr(path, attr->name, attr->attr, attr->size, 0, XATTR_NOFOLLOW);
		offset = ft_strlen(attr->name) + 1;
		ft_lstconstruct(&attrs, &ptr, ft_lstnew(attr, sizeof(t_xattr)));
		i += offset;
	}
}

void	get_xattr_names(t_file *file)
{
	char	*attr_names;
	t_list	*attrs;
	char	*path;

	attrs = NULL;
	path = make_path(file->path, file->dirent.d_name);
	file->xattrs_buffsize = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (file->xattrs_buffsize < 0)
		file->xattrs_buffsize = 0;
	attr_names = ft_strnew(file->xattrs_buffsize);
	listxattr(path, attr_names, file->xattrs_buffsize, XATTR_NOFOLLOW);
	make_xattr_names(file, attr_names, attrs, path);
	file->xattrs = attrs;
	ft_strdel(&path);
	ft_strdel(&attr_names);
}

void	ft_display_xattrs(t_file *file)
{
	t_list	*ptr;

	ptr = file->xattrs;
	while (ptr != NULL)
	{
		ft_putstr("\t");
		ft_putstr(((t_xattr*)ptr->content)->name);
		ft_putstr("\t");
		ft_putnbr_fixed(((t_xattr*)ptr->content)->size, 3, 1);
		ft_putstr(" \n");
		ptr = ptr->next;
	}
}
