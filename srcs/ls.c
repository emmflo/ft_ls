#include "ft_ls.h"
#include <stdio.h>

char	*make_path(char *path, char *name)
{
	char	*str;
	int		offset;
	
	offset = 0;
	if (path[ft_strlen(path)-1] != '/')
		offset = 1;
	str = ft_strnew(ft_strlen(path) + ft_strlen(name) + offset);
	ft_strcat(str, path);
	if (offset)
		ft_strcat(str, "/");
	ft_strcat(str, name);
	return (str);
}

int		check_error(char *pre)
{
	if (errno != 0)
	{
		ft_putstr("ls: ");
		ft_putstr(pre);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		return (-1);
	}
	return (0);
}

int		ft_d_namecmp(void *a, void *b)
{
	return (ft_strcmp(((t_file*)a)->dirent.d_name, ((t_file*)b)->dirent.d_name));
}

int		ft_d_namecmp_r(void *a, void *b)
{
	return (ft_d_namecmp(b, a));
}

int		ft_st_mtimcmp(void *a, void *b)
{
	struct stat		*stat1;
	struct stat		*stat2;

	stat1 = &((t_file*)a)->stat;
	stat2 = &((t_file*)b)->stat;
	if (stat1->st_mtimespec.tv_sec < stat2->st_mtimespec.tv_sec)
		return (1);
	else if (stat1->st_mtimespec.tv_sec > stat2->st_mtimespec.tv_sec)
		return (-1);
	else
	{
		if (stat1->st_mtimespec.tv_nsec < stat2->st_mtimespec.tv_nsec)
			return (1);
		else if (stat1->st_mtimespec.tv_nsec > stat2->st_mtimespec.tv_nsec)
			return (-1);
		else
			return (ft_d_namecmp(a, b));
	}
}

int		ft_st_mtimcmp_r(void *a, void *b)
{
	return (ft_st_mtimcmp(b, a));
}

t_list	*ft_sortfiles(t_list *files, char *toptions)
{
	if (toptions[o_t])
	{
		if (toptions[o_r])
			return (ft_merge_sort(files, &ft_st_mtimcmp_r));
		else
			return (ft_merge_sort(files, &ft_st_mtimcmp));
	}
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

int		ft_filter_A(t_list *elem)
{
	if (ft_strcmp(((t_file*)elem->content)->dirent.d_name, ".") == 0 ||
		ft_strcmp(((t_file*)elem->content)->dirent.d_name, "..") == 0)
		return (0);
	else
		return (1);
}

t_list	*ft_filterlist(t_list *files, char *toptions)
{
	if (toptions[o_a])
		return (files);
	else if (toptions[o_A])
		return (ft_lstfilter(files, &ft_filter_A));
	else
		return (ft_lstfilter(files, &ft_filter_dot));
}

t_list	*ft_makefilelist(char *path, DIR *dir);
void	ft_dir(char *path, char *toptions)
{
	DIR		*dir;
	t_list	*files;

	errno = 0;
	dir = opendir(path);
	if (check_error(path))
		return ;
	files = ft_makefilelist(path, dir);
	files = ft_filterlist(files, toptions);
	files = ft_sortfiles(files, toptions);
	while (files != NULL)
	{
		printf("%s\n", ((t_file*)files->content)->dirent.d_name);
		files = files->next;
	}
	toptions = NULL;
}

t_list	*ft_makefilelist(char *path, DIR *dir)
{
	struct dirent	*dirent;
	struct stat		*stat;
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
		stat = malloc(sizeof(struct stat));
		lstat(make_path(path, dirent->d_name), stat);
		file = malloc(sizeof(*file));
		file->dirent = *dirent;
		file->path = ft_strdup(path);
		file->stat = *stat;
		if (ptr == NULL)
		{
			ptr = ft_lstnew(file, sizeof(*file));
			files = ptr;
		}
		else
		{
			ptr->next = ft_lstnew(file, sizeof(*file));
			ptr = ptr->next;
		}
	}
	return (files);
}

void	ft_ls(char *options, t_list *dirs)
{
	char	*toptions;

	toptions = lsopt(options);
	if (dirs == NULL)
		ft_dir("./", toptions);
	else
	{
		while (dirs != NULL)
		{
			ft_dir(dirs->content, toptions);
			dirs = dirs->next;
		}
	}
}
