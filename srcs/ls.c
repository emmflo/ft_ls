/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:01:17 by eflorenz          #+#    #+#             */
/*   Updated: 2017/04/11 13:46:02 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

char	*make_path(char *path, char *name)
{
	char	*str;
	int		offset;

	offset = 0;
	if (path[ft_strlen(path) - 1] != '/')
		offset = 1;
	str = ft_strnew(ft_strlen(path) + ft_strlen(name) + offset);
	ft_strcat(str, path);
	if (offset)
		ft_strcat(str, "/");
	ft_strcat(str, name);
	return (str);
}

int		ft_d_namecmp(void *a, void *b)
{
	return (ft_strcmp(((t_file*)a)->dirent.d_name,
				((t_file*)b)->dirent.d_name));
}

int		ft_d_namecmp_r(void *a, void *b)
{
	return (ft_d_namecmp(b, a));
}

int		ft_st_timcmp(struct timespec *a, struct timespec *b)
{
	if (a->tv_sec < b->tv_sec)
		return (1);
	else if (a->tv_sec > b->tv_sec)
		return (-1);
	else
	{
		if (a->tv_nsec < b->tv_nsec)
			return (1);
		else if (a->tv_nsec > b->tv_nsec)
			return (-1);
		else
			return (0);
		return (ft_d_namecmp(a, b));
	}
}

int		ft_st_mtimcmp(void *a, void *b)
{
	int				ret;
	struct stat		*stat1;
	struct stat		*stat2;

	stat1 = &((t_file*)a)->stat;
	stat2 = &((t_file*)b)->stat;
	ret = ft_st_timcmp(&stat1->st_mtimespec, &stat2->st_mtimespec);
	if (ret == 0)
		return (ft_d_namecmp(a, b));
	else
		return (ret);
}

int		ft_st_mtimcmp_r(void *a, void *b)
{
	return (ft_st_mtimcmp(b, a));
}

int		ft_st_atimcmp(void *a, void *b)
{
	int				ret;
	struct stat		*stat1;
	struct stat		*stat2;

	stat1 = &((t_file*)a)->stat;
	stat2 = &((t_file*)b)->stat;
	ret = ft_st_timcmp(&stat1->st_atimespec, &stat2->st_atimespec);
	if (ret == 0)
		return (ft_d_namecmp(a, b));
	else
		return (ret);
}

int		ft_st_atimcmp_r(void *a, void *b)
{
	return (ft_st_atimcmp(b, a));
}

int		ft_st_ctimcmp(void *a, void *b)
{
	int				ret;
	struct stat		*stat1;
	struct stat		*stat2;

	stat1 = &((t_file*)a)->stat;
	stat2 = &((t_file*)b)->stat;
	ret = ft_st_timcmp(&stat1->st_ctimespec, &stat2->st_ctimespec);
	if (ret == 0)
		return (ft_d_namecmp(a, b));
	else
		return (ret);
}

int		ft_st_ctimcmp_r(void *a, void *b)
{
	return (ft_st_ctimcmp(b, a));
}

int		ft_st_btimcmp(void *a, void *b)
{
	int				ret;
	struct stat		*stat1;
	struct stat		*stat2;

	stat1 = &((t_file*)a)->stat;
	stat2 = &((t_file*)b)->stat;
	ret = ft_st_timcmp(&stat1->st_birthtimespec, &stat2->st_birthtimespec);
	if (ret == 0)
		return (ft_d_namecmp(a, b));
	else
		return (ret);
}

int		ft_st_btimcmp_r(void *a, void *b)
{
	return (ft_st_btimcmp(b, a));
}

int		ft_st_sizecmp(void *a, void *b)
{
	struct stat		*stat1;
	struct stat		*stat2;

	stat1 = &((t_file*)a)->stat;
	stat2 = &((t_file*)b)->stat;
	if (stat1->st_size < stat2->st_size)
		return (1);
	else if (stat1->st_size > stat2->st_size)
		return (-1);
	else
		return (ft_d_namecmp(a, b));
}

int		ft_st_sizecmp_r(void *a, void *b)
{
	return (ft_st_sizecmp(b, a));
}

t_list	*ft_sortfiles_bytime_c(t_list *files, char *toptions)
{
	if (toptions[o_r])
		return (ft_merge_sort(files, &ft_st_ctimcmp_r));
	else
		return (ft_merge_sort(files, &ft_st_ctimcmp));
}

t_list	*ft_sortfiles_bytime_u(t_list *files, char *toptions)
{
	if (toptions[o_r])
		return (ft_merge_sort(files, &ft_st_atimcmp_r));
	else
		return (ft_merge_sort(files, &ft_st_atimcmp));
}

t_list	*ft_sortfiles_bytime_b(t_list *files, char *toptions)
{
	if (toptions[o_r])
		return (ft_merge_sort(files, &ft_st_btimcmp_r));
	else
		return (ft_merge_sort(files, &ft_st_btimcmp));
}

t_list	*ft_sortfiles_bytime_m(t_list *files, char *toptions)
{
	if (toptions[o_r])
		return (ft_merge_sort(files, &ft_st_mtimcmp_r));
	else
		return (ft_merge_sort(files, &ft_st_mtimcmp));
}

t_list	*ft_sortfiles_bytime(t_list *files, char *toptions)
{
	if (toptions[o_c])
		return (ft_sortfiles_bytime_c(files, toptions));
	else if (toptions[o_u])
		return (ft_sortfiles_bytime_u(files, toptions));
	else if (toptions[o_U])
		return (ft_sortfiles_bytime_b(files, toptions));
	else
		return (ft_sortfiles_bytime_m(files, toptions));
}

t_list	*ft_sortfiles(t_list *files, char *toptions)
{
	if (toptions[o_f])
		return (files);
	else if (toptions[o_S])
	{
		if (toptions[o_r])
			return (ft_merge_sort(files, &ft_st_sizecmp_r));
		else
			return (ft_merge_sort(files, &ft_st_sizecmp));
	}
	else if (toptions[o_t])
		return (ft_sortfiles_bytime(files, toptions));
	else
	{
		if (toptions[o_r])
			return (ft_merge_sort(files, &ft_d_namecmp_r));
		else
			return (ft_merge_sort(files, &ft_d_namecmp));
	}
}

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
	if (ft_check_errno(((char*)elem->content)))
		ret = 0;
	else
	{
		ret = 1;
		closedir(dir);
	}
	return (ret);
}

void	ft_delfile(void *file, size_t size)
{
	size = 0;
	//free(((t_file*)file)->stat);
	//free(((t_file*)file)->dirent);
	ft_strdel(&(((t_file*)file)->path));
	free((t_file*)file);
}

void	ft_filterlist(t_list **files, char *toptions)
{
	if (toptions[o_a])
		;
	else if (toptions[o_A])
		ft_lstinplacefilter(files, &ft_filter_a_, &ft_delfile);
	else
		ft_lstinplacefilter(files, &ft_filter_dot, &ft_delfile);
}

void	ft_recursive(t_list *files, char *toptions)
{
	char	*str;
	char	*name;

	while (files != NULL)
	{
		name = ((t_file*)files->content)->dirent.d_name;
		if ((((t_file*)files->content)->stat.st_mode & S_IFMT) == S_IFDIR &&
				ft_strcmp(name, ".") != 0 &&
				ft_strcmp(name, "..") != 0)
		{
			ft_putchar('\n');
			str = make_path(((t_file*)files->content)->path, name);
			ft_putstr(str);
			ft_putstr(":\n");
			ft_dir(str, toptions);
			free(str);
		}
		files = files->next;
	}
}

void	ft_dir(char *path, char *toptions)
{
	DIR		*dir;
	t_list	*files;

	errno = 0;
	dir = opendir(path);
	if (ft_check_errno(path))
		return ;
	files = ft_makefilelist(path, dir);
	ft_filterlist(&files, toptions);
	files = ft_sortfiles(files, toptions);
	ft_displayls(files, toptions);
	if (toptions[o_R])
		ft_recursive(files, toptions);
	ft_lstdel(&files, &ft_delfile);
	closedir(dir);
}

t_file	*ft_makefile(char *path, struct dirent *dirent)
{
	struct stat	*stat;
	t_file		*file;
	char		*str;

	stat = malloc(sizeof(struct stat));
	str = make_path(path, dirent->d_name);
	lstat(str, stat);
	free(str);
	file = malloc(sizeof(*file));
	file->dirent = *dirent;
	file->path = ft_strdup(path);
	file->stat = *stat;
	free(stat);
	return (file);
}

t_list	*ft_makefilelist(char *path, DIR *dir)
{
	struct dirent	*dirent;
	t_list			*files;
	t_list			*ptr;

	ptr = NULL;
	files = NULL;
	while (1)
	{
		dirent = readdir(dir);
		if (dirent == NULL)
			break ;
		ft_lstconstruct(&files, &ptr, ft_lstnew(ft_makefile(path, dirent), sizeof(t_file)));
	}
	return (files);
}

void	ft_deldir(void *str, size_t size)
{
	//ft_strdel(str);
	str = NULL;
	size = 0;
}

void	ft_ls(char *options, t_list *dirs)
{
	char	*toptions;
	int		i;
	t_list	*first;

	i = 0;
	first = dirs;
	toptions = ft_strnew(NB_OPTIONS);
	while (i < NB_OPTIONS)
		toptions[i++] = 0;
	ft_get_prefs(toptions);
	lsopt(options, toptions);
	free(options);
	if (dirs == NULL)
		ft_dir("./", toptions);
	else if (dirs->next == NULL)
	{
		ft_dir(dirs->content, toptions);
	}
	else
	{
		ft_lstinplacefilter(&dirs, &ft_filter_errno, &ft_deldir);
		while (dirs != NULL)
		{
			ft_putstr(dirs->content);
			ft_putstr(":\n");
			ft_dir(dirs->content, toptions);
			dirs = dirs->next;
			if (dirs != NULL)
				ft_putchar('\n');
		}
	}
	if (dirs != NULL)
		ft_lstdel(&first, &ft_deldir);
	ft_strdel(&toptions);
}
