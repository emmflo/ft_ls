/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:08:14 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/15 09:22:14 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_filter_dot(t_list *elem)
{
	if (((t_file*)elem->content)->dirent.d_name[0] == '.')
		return (0);
	else
		return (1);
}

int		ft_filter_a_(t_list *elem)
{
	if (ft_strcmp(((t_file*)elem->content)->dirent.d_name, ".") == 0 ||
		ft_strcmp(((t_file*)elem->content)->dirent.d_name, "..") == 0)
		return (0);
	else
		return (1);
}

int		ft_filter_errno(t_list *elem)
{
	DIR		*dir;
	int		ret;

	errno = 0;
	dir = opendir(((char*)elem->content));
	if (errno == ENOTDIR)
		ret = 0;
	else if (ft_check_errno(((char*)elem->content)))
		ret = 0;
	else
	{
		ret = 1;
		closedir(dir);
	}
	return (ret);
}

void	ft_filterlist(t_list **files)
{
	if (g_toptions[o_a])
		;
	else if (g_toptions[o_A])
		ft_lstinplacefilter(files, &ft_filter_a_, &ft_delfile);
	else
		ft_lstinplacefilter(files, &ft_filter_dot, &ft_delfile);
}

void	ft_delfile(void *file, size_t size)
{
	(void)size;
	if ((((t_file*)file)->path) != NULL)
		ft_strdel(&(((t_file*)file)->path));
	free((t_file*)file);
}
