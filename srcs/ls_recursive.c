/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:16:39 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 03:16:46 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
