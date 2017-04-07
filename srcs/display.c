#include "ft_ls.h"
#include <stdio.h>
#include <stdlib.h>

extern int	g_columns;

char	*ft_str_name(t_list *files, char *toptions)
{
	char		*str;
	struct stat	*buff_stat;

	str = ft_strnew(ft_strlen(((t_file*)files->content)->dirent.d_name) + 1);
	buff_stat = &((t_file*)files->content)->stat;
	ft_strcpy(str, ((t_file*)files->content)->dirent.d_name);
	if (toptions[o_F])
	{
		if ((buff_stat->st_mode & S_IFMT) == S_IFDIR)
			ft_strcat(str, "/");
		if ((buff_stat->st_mode & S_IFMT) == S_IFREG && (buff_stat->st_mode & S_IXUSR) != 0)
			ft_strcat(str, "*");
		if ((buff_stat->st_mode & S_IFMT) == S_IFLNK)
			ft_strcat(str, "@");
		if ((buff_stat->st_mode & S_IFMT) == S_IFSOCK)
			ft_strcat(str, "=");
		if ((buff_stat->st_mode & S_IFMT) == S_IFWHT)
			ft_strcat(str, "%");
		if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
			ft_strcat(str, "|");
	}
	return (str);
}

void	ft_display_name(t_list *files, char *toptions)
{
	ft_putstr(ft_str_name(files, toptions));
}

void	ft_display_1(t_list *files, char *toptions)
{
	while (files != NULL)
	{
		ft_display_name(files, toptions);
		ft_putchar('\n');
		files = files->next;
	}
}

int		ft_get_max_len(t_list *files)
{
	int		max;
	int		tmp;

	max = 0;
	while (files != NULL)
	{
		tmp = ft_strlen(((t_file*)files->content)->dirent.d_name);
		max = tmp > max ? tmp : max;
		files = files->next;
	}
	return (max);
}

void	ft_display_x(t_list *files, char *toptions)
{
	int		max;
	int		nb_columns;
	int		i;
	int		j;
	int		len;
	char	*str;

	max = ft_get_max_len(files);
	max = max + (8 - max % 8);
	nb_columns = g_columns / max;
	i = 0;
	while (files != NULL)
	{
		str = ft_str_name(files, toptions);
		len = ft_strlen(str);
		ft_putstr(str);
		j = 0;
		if (len % 8 != 0)
			ft_putchar('\t');
		while (j++ < (max - len) / 8)
			ft_putchar('\t');
		if (i++ % nb_columns == nb_columns - 1)
			ft_putchar('\n');
		files = files->next;
	}
	if (i % nb_columns != 0)
		ft_putchar('\n');
}

t_list	**ft_make_file_tab(t_list *files)
{
	t_list	**tab;
	int		len;
	int		i;

	len = ft_lstlen(files);
	if (!(tab = malloc(sizeof(t_list) * len))) 
		exit(1);
	i = 0;
	while (files != NULL)
	{
		tab[i] = files;
		i++;
		files = files->next;
	}
	return (tab);
}

void	ft_display_C(t_list *files, char *toptions)
{
	t_list	**tab;
	int		max;
	int		nb_columns;
	int		nb_lines;
	int		i;
	int		j;
	int		k;
	int		len;
	int		tab_len;
	char	*str;

	tab = ft_make_file_tab(files);
	tab_len = ft_lstlen(files);
	max = ft_get_max_len(files);
	max = max + (8 - max % 8);
	nb_columns = g_columns / max;
	nb_lines = tab_len / nb_columns;
	nb_lines += tab_len % nb_columns == 0 ? 0 : 1;
	i = 0;
	while (i < nb_lines)
	{
		j = i;
		while (j < tab_len)
		{
			str = ft_str_name(tab[j], toptions);
			len = ft_strlen(str);
			ft_putstr(str);
			k = 0;
			if (len % 8 != 0)
				ft_putchar('\t');
			while (k++ < (max - len) / 8)
				ft_putchar('\t');
			j += nb_lines;
		}
		i++;
		ft_putchar('\n');
	}
}

int		ft_nbrsize(int nb);
void	ft_putnbr_fixed(int nb, int column_size, int right)
{
	column_size -= ft_nbrsize(nb);
	if (!right)
		ft_putnbr(nb);
	while (column_size > 0)
	{
		ft_putchar(' ');
		column_size--;
	}
	if (right)
		ft_putnbr(nb);
}

void	ft_putstr_fixed(char *str, int column_size, int right)
{
	column_size -= ft_strlen(str);
	if (!right)
		ft_putstr(str);
	while (column_size > 0)
	{
		ft_putchar(' ');
		column_size--;
	}
	if (right)
		ft_putstr(str);
}

t_column_sizes	*ft_get_column_size(t_list *files);
char	*ft_permission_to_str(struct stat *buff_stat)
{
	char	*permissions;
	int		i;

	permissions = ft_strnew(9);
	i = 0;
	while (i < 9)
		permissions[i++] = '-';
	permissions[9] = '\0';
	if ((buff_stat->st_mode & S_IRUSR) != 0)
		permissions[0] = 'r';
	if ((buff_stat->st_mode & S_IWUSR) != 0)
		permissions[1] = 'w';
	if ((buff_stat->st_mode & S_IXUSR) != 0)
		permissions[2] = 'x';
	if ((buff_stat->st_mode & S_IRGRP) != 0)
		permissions[3] = 'r';
	if ((buff_stat->st_mode & S_IWGRP) != 0)
		permissions[4] = 'w';
	if ((buff_stat->st_mode & S_IXGRP) != 0)
		permissions[5] = 'x';
	if ((buff_stat->st_mode & S_IROTH) != 0)
		permissions[6] = 'r';
	if ((buff_stat->st_mode & S_IWOTH) != 0)
		permissions[7] = 'w';
	if ((buff_stat->st_mode & S_IXOTH) != 0)
		permissions[8] = 'x';
	return (permissions);
}

char	ft_type_to_char(struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	if ((buff_stat->st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	if ((buff_stat->st_mode & S_IFMT) == S_IFREG)
		return ('-');
	if ((buff_stat->st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	if ((buff_stat->st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	if ((buff_stat->st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	return ('-');
}

char	*link_to_str(char *path, struct stat *buff_stat)
{
	char			*str;
	int				size;
	int				ret;

	size = buff_stat->st_size;
	//if (size == 0)
	//	size = PATH_MAX;
	str = ft_strnew(size);
	ret = readlink(path, str, size);
	if (ret == -1)
	{
		exit(EXIT_FAILURE);
	}
	str[ret] = '\0';
	return (str);
}

void	print_date(struct stat *buff_stat)
{
	char			*str;

	str = ctime(&(buff_stat->st_mtimespec.tv_sec));
	str[ft_strlen(str) - 9] = '\0';
	ft_putstr(str + 4);
	ft_putchar(' ');
}

void	ft_display_l_file(t_list *file, t_column_sizes *column_sizes, char *toptions)
{
	t_file		*file_content;
	struct stat	*buff_stat;

	file_content = ((t_file*)file->content);
	buff_stat = &file_content->stat;
	ft_putchar(ft_type_to_char(buff_stat));
	ft_putstr(ft_permission_to_str(buff_stat));
	ft_putstr("  ");
	ft_putnbr_fixed(buff_stat->st_nlink, column_sizes->nlink, 1);
	ft_putstr(" ");
	if (!toptions[o_g])
	{
		ft_putstr_fixed(getpwuid(buff_stat->st_uid)->pw_name, column_sizes->user, 0);
		ft_putstr("  ");
	}
	ft_putstr_fixed(getgrgid(buff_stat->st_gid)->gr_name, column_sizes->group, 0);
	ft_putstr("  ");
	ft_putnbr_fixed(buff_stat->st_size, column_sizes->size, 1);
	ft_putstr(" ");
	print_date(buff_stat);
	ft_display_name(file, toptions);
	if (ft_type_to_char(buff_stat) == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr(link_to_str(make_path(file_content->path, file_content->dirent.d_name), buff_stat));
	}
	ft_putchar('\n');
}

long long int	ft_get_total(t_list *files)
{
	long long int	total;

	total = 0;
	while (files != NULL)
	{
		//printf("%lld %d\n", ((t_file*)files->content)->stat.st_blocks, ((t_file*)files->content)->stat.st_blksize);
		total += ((t_file*)files->content)->stat.st_blocks * (((t_file*)files->content)->stat.st_blksize / 4096);
		files = files->next;
	}
	return (total);
}

void	ft_display_l(t_list *files, char *toptions)
{
	t_column_sizes	*column_sizes;
	long long int	total;

	column_sizes = ft_get_column_size(files);
	total = ft_get_total(files);
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
	while (files != NULL)
	{
		ft_display_l_file(files, column_sizes, toptions);
		files = files->next;
	}
}

int		ft_nbrsize(int nb)
{
	int	i;
	int	neg;

	neg = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
	}
	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i + neg);
}

t_column_sizes	*ft_get_column_size(t_list *files)
{
	int	tmp;
	t_column_sizes	*column_sizes;

	if (!(column_sizes = (t_column_sizes*)malloc(sizeof(t_column_sizes))))
		exit(1);
	while (files != NULL)
	{
		tmp = ft_nbrsize(((t_file*)files->content)->stat.st_nlink);
		column_sizes->nlink = column_sizes->nlink < tmp ? tmp : column_sizes->nlink;
		tmp = ft_nbrsize(((t_file*)files->content)->stat.st_size);	
		column_sizes->size = column_sizes->size < tmp ? tmp : column_sizes->size;
		tmp = ft_strlen(getpwuid(((t_file*)files->content)->stat.st_uid)->pw_name);
		column_sizes->user = column_sizes->user < tmp ? tmp : column_sizes->user;
		tmp = ft_strlen(getgrgid(((t_file*)files->content)->stat.st_gid)->gr_name);
		column_sizes->group = column_sizes->group < tmp ? tmp : column_sizes->group;
		files = files->next;
	}
	return (column_sizes);
}

void	ft_displayls(t_list *files, char *toptions)
{
	if (toptions[o_l])
		ft_display_l(files, toptions);
	else if (toptions[o_x])
		ft_display_x(files, toptions);
	else if (toptions[o_C])
		ft_display_C(files, toptions);
	//else if (toptions[o_1])
	else
		ft_display_1(files, toptions);
}
