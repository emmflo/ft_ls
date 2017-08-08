/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:53:58 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/08 22:46:19 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

char	*make_path(char *path, char *name)
{
	char	*str;
	int		offset;
	int		path_len;

	offset = 0;
	path_len = ft_strlen(path);
	if (path_len > 0 && path[path_len - 1] != '/')
		offset = 1;
	str = ft_strnew(path_len + ft_strlen(name) + offset);
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

t_list	*ft_sortfiles_bytime_c(t_list *files)
{
	if (g_toptions[o_r])
		return (ft_merge_sort(files, &ft_st_ctimcmp_r));
	else
		return (ft_merge_sort(files, &ft_st_ctimcmp));
}

t_list	*ft_sortfiles_bytime_u(t_list *files)
{
	if (g_toptions[o_r])
		return (ft_merge_sort(files, &ft_st_atimcmp_r));
	else
		return (ft_merge_sort(files, &ft_st_atimcmp));
}

t_list	*ft_sortfiles_bytime_b(t_list *files)
{
	if (g_toptions[o_r])
		return (ft_merge_sort(files, &ft_st_btimcmp_r));
	else
		return (ft_merge_sort(files, &ft_st_btimcmp));
}

t_list	*ft_sortfiles_bytime_m(t_list *files)
{
	if (g_toptions[o_r])
		return (ft_merge_sort(files, &ft_st_mtimcmp_r));
	else
		return (ft_merge_sort(files, &ft_st_mtimcmp));
}

t_list	*ft_sortfiles_bytime(t_list *files)
{
	if (g_toptions[o_c])
		return (ft_sortfiles_bytime_c(files));
	else if (g_toptions[o_u])
		return (ft_sortfiles_bytime_u(files));
	else if (g_toptions[o_U])
		return (ft_sortfiles_bytime_b(files));
	else
		return (ft_sortfiles_bytime_m(files));
}

t_list	*ft_sortfiles(t_list *files)
{
	if (g_toptions[o_f])
		return (files);
	else if (g_toptions[o_S])
	{
		if (g_toptions[o_r])
			return (ft_merge_sort(files, &ft_st_sizecmp_r));
		else
			return (ft_merge_sort(files, &ft_st_sizecmp));
	}
	else if (g_toptions[o_t])
		return (ft_sortfiles_bytime(files));
	else
	{
		if (g_toptions[o_r])
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

void	ft_delfile(void *file, size_t size)
{
	(void)size;
	ft_strdel(&(((t_file*)file)->path));
	free((t_file*)file);
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

void	ft_delino(void *ino, size_t size)
{
	(void)size;
	free(ino);
}

int		ft_inoinlst(t_list *visited, ino_t ino)
{
	while (visited != NULL)
	{
		if (*((ino_t*)visited->content) == ino)
			return (1);
		visited = visited->next;
	}
	return (0);
}

void	ft_print_header(t_file *content, char *name)
{
	char			*str;

	ft_putchar('\n');
	str = make_path(content->path, name);
	ft_putstr(str);
	ft_putstr(":\n");
	ft_dir(str);
	free(str);
}

void	ft_manage_ptr_start(char *path, t_list *visited, t_list *ptr,
		t_list *prev)
{
	struct stat		buff_stat;
	ino_t			*tmp;

	stat(path, &buff_stat);
	if (!(tmp = malloc(sizeof(ino_t))))
		return ;
	*tmp = buff_stat.st_ino;
	prev = ptr;
	ft_lstconstruct(&visited, &ptr, ft_lstnew(tmp, sizeof(ino_t)));
}

void	ft_recursive(t_list *files, char *path)
{
	static t_list	*visited = NULL;
	static t_list	*ptr = NULL;
	t_list			*prev;
	char			*name;

	prev = NULL;
	ft_manage_ptr_start(path, visited, ptr, prev);
	while (files != NULL)
	{
		name = ((t_file*)files->content)->dirent.d_name;
		if (ft_strcmp(name, ".") == 0 || ft_strcmp(name, "..") == 0)
			;
		else if (ft_inoinlst(visited, ((t_file*)files->content)->stat.st_ino))
			ft_print_error(name, "directory causes a cycle");
		else if ((((t_file*)files->content)->stat.st_mode & S_IFMT) == S_IFDIR)
			ft_print_header(((t_file*)files->content), name);
		files = files->next;
	}
	if (ptr != visited)
	{
		ft_lstdel(&ptr, &ft_delino);
		ptr = prev;
		ptr->next = NULL;
	}
}

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

struct dirent	*ft_makedirent(char *path)
{
	struct dirent	*dirent;

	if (!(dirent = malloc(sizeof(struct dirent))))
		return (NULL);
	ft_strcpy(dirent->d_name, path);
	return (dirent);
}

t_file	*ft_makefile_commit(char *path, struct dirent *dirent,
		struct stat *buff_stat)
{
	t_file		*file;

	file = malloc(sizeof(*file));
	file->path = ft_strdup(path);
	file->dirent = *dirent;
	file->stat = *buff_stat;
	get_xattr_names(file);
	ft_get_acls(file);
	free(buff_stat);
	return (file);
}

t_file	*ft_makefile(char *path, struct dirent *dirent)
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

t_list	*ft_makefilelist(char *path, DIR *dir)
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
			ft_lstconstruct(&files, &ptr, ft_lstnew(file,
			sizeof(t_file)));
	}
	return (files);
}

t_list	*ft_makefilelist_d(t_list *dirs)
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

void	ft_deldir(void *str, size_t size)
{
	str = NULL;
	(void)size;
}

char	*ft_newg_toptions(void)
{
	int		i;

	i = 0;
	g_toptions = ft_strnew(NB_OPTIONS);
	while (i < NB_OPTIONS)
		g_toptions[i++] = 0;
	return (g_toptions);
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

void	ft_ls(char *options, t_list *dirs)
{
	char	*g_toptions;
	t_list	*ptr;

	g_toptions = ft_newg_toptions();
	ft_get_prefs(g_toptions);
	lsopt(options);
	ft_strdel(&options);
	if (dirs == NULL)
		dirs = ft_lstnew(ft_strdup("."), 2);
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
