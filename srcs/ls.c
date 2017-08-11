/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:53:58 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 03:29:03 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_dir(char *path)
{
	DIR		*dir;
	t_list	*files;

	errno = 0;
	dir = opendir(path);
	if (errno == ENOTDIR)
		files = ft_lstnew(ft_makefile(path, NULL), sizeof(t_file));
	else if (ft_check_errno(path))
		return ;
	else
	{
		files = ft_makefilelist(path, dir);
		closedir(dir);
	}
	ft_filterlist(&files);
	files = ft_sortfiles(files);
	ft_displayls(files);
	if (g_toptions[o_R])
		ft_recursive(files, path);
	ft_lstdel(&files, &ft_delfile);
}

void	ft_list_d(t_list *dirs)
{
	t_list	*files;

	files = ft_makefilelist_d(dirs);
	ft_filterlist(&files);
	files = ft_sortfiles(files);
	ft_displayls(files);
	ft_lstdel(&files, &ft_delfile);
}

void	ft_files(t_list *dirs)
{
	struct stat	stat;
	t_list		*files;
	t_list		*ptr;

	files = NULL;
	ptr = NULL;
	while (dirs != NULL)
	{
		lstat(dirs->content, &stat);
		if ((stat.st_mode & S_IFMT) != S_IFDIR)
		{
			ft_lstconstruct(&files, &ptr,
					ft_lstnew(dirs->content, sizeof(dirs->content)));
		}
		dirs = dirs->next;
	}
	ft_list_d(files);
	if (files != NULL)
		ft_putchar('\n');
}

void	ft_ls_start(char *options, t_list **dirs)
{
	g_toptions = ft_newg_toptions();
	ft_get_prefs(g_toptions);
	lsopt(options);
	ft_strdel(&options);
	if (*dirs == NULL)
		*dirs = ft_lstnew(ft_strdup("."), 2);
}

void	ft_ls(char *options, t_list *dirs)
{
	t_list	*ptr;

	ft_ls_start(options, &dirs);
	if (g_toptions[o_d])
		ft_list_d(dirs);
	else if (dirs->next == NULL)
		ft_dir(dirs->content);
	else
	{
		ptr = ft_lstfilter(dirs, &ft_filter_errno);
		ft_files(dirs);
		while (ptr != NULL)
		{
			ft_putstr(ptr->content);
			ft_putstr(":\n");
			ft_dir(ptr->content);
			ptr = ptr->next;
			if (ptr != NULL)
				ft_putchar('\n');
		}
		if (ptr != NULL)
			ft_lstdel(&ptr, &ft_deldir);
	}
	ft_lstdel(&dirs, &ft_deldir);
	ft_strdel(&g_toptions);
}
