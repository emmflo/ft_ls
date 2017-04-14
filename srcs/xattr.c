/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xattr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:28:13 by eflorenz          #+#    #+#             */
/*   Updated: 2017/04/14 12:08:01 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_xattr_names(t_file *file)
{
	int		buff_size;
	char	*attr_names;
	t_list	*attrs;
	t_list	*ptr;
	ssize_t	i;
	ssize_t	offset;
	t_xattr	*attr;
	char	*path;

	attrs = NULL;
	ptr = NULL;
	path = make_path(file->path, file->dirent.d_name);
	buff_size = listxattr(path, NULL, 0, 0);
	attr_names = ft_strnew(buff_size);
	listxattr(path, attr_names, buff_size, 0);
	i = 0;
	while (i < buff_size)
	{
		if (!(attr = malloc(sizeof(t_xattr))))
			return ;
		attr->name = ft_strdup(&attr_names[i]);
		attr->size = getxattr(path, attr->name, NULL, 0, 0, 0);
		//printf("%zd\n", attr->size);
		if (!(attr->attr = malloc(attr->size)))
			return ;
		getxattr(path, attr->name, attr->attr, attr->size, 0, 0);
		offset = ft_strlen(attr->name) + 1;
		ft_lstconstruct(&attrs, &ptr, ft_lstnew(attr, sizeof(t_xattr)));
		i += offset;
	}
	file->xattrs = attrs;
}

void	ft_display_xattrs(t_file *file)
{
	t_list	*ptr;

	ptr = file->xattrs;
	while (ptr !=NULL)
	{
		ft_putstr("\t");
		ft_putstr(((t_xattr*)ptr->content)->name);
		ft_putstr("\t");
		ft_putnbr_fixed(((t_xattr*)ptr->content)->size, 3, 1);
		ft_putstr("\n");
		ptr = ptr->next;
	}
}