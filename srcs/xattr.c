/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xattr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:28:13 by eflorenz          #+#    #+#             */
/*   Updated: 2018/01/02 08:44:44 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_delattrs(void *content, size_t size)
{
	(void)size;
	free(((t_xattr*)content)->attr);
	ft_strdel(&(((t_xattr*)content)->name));
	free((t_xattr*)content);
}

void	make_xattr_names(t_file *file, char *attr_names, t_list **attrs,
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
		check_malloc(attr = malloc(sizeof(t_xattr)));
		attr->name = ft_strdup(&attr_names[i]);
		attr->size = getxattr(path, attr->name, NULL, 0, 0, XATTR_NOFOLLOW);
		check_malloc(attr->attr = malloc(attr->size));
		getxattr(path, attr->name, attr->attr, attr->size, 0, XATTR_NOFOLLOW);
		offset = ft_strlen(attr->name) + 1;
		ft_lstconstruct(attrs, &ptr,
			check_malloc(ft_lstnew(attr, sizeof(t_xattr))));
		free(attr);
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
	if (file->xattrs_buffsize <= 0)
		file->xattrs_buffsize = 0;
	check_malloc(attr_names = ft_strnew(file->xattrs_buffsize));
	listxattr(path, attr_names, file->xattrs_buffsize, XATTR_NOFOLLOW);
	make_xattr_names(file, attr_names, &attrs, path);
	file->xattrs = attrs;
	ft_strdel(&attr_names);
	ft_strdel(&path);
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
