/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:58:29 by eflorenz          #+#    #+#             */
/*   Updated: 2017/04/19 13:33:07 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <stdlib.h>

extern int	g_columns;
extern char	*g_colors;
extern char	g_colors_tab[][6];
extern char	*lscolors;

char	*ft_itoa(int nb)
{
	int		len;
	char	*str;
	int		i;
	int		neg;

	len = ft_nbrsize(nb);
	str = ft_strnew(len);
	neg = 0;
	if (nb == 0)
		return (strcpy(str, "0"));
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
		str[0] = '-';
	}
	i = len - neg - 1;
	while (i >= 0)
	{
		str[neg + i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (str);
}

void	ft_putino(t_list *files)
{
	ft_putnbr(((t_file*)files->content)->stat.st_ino);
	ft_putchar(' ');
}

char	*ft_f__str(struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_IFMT) == S_IFDIR)
		return ("/");
	else if ((buff_stat->st_mode & S_IFMT) == S_IFREG &&
			(buff_stat->st_mode & S_IXUSR) != 0)
		return ("*");
	else if ((buff_stat->st_mode & S_IFMT) == S_IFLNK)
		return ("@");
	else if ((buff_stat->st_mode & S_IFMT) == S_IFSOCK)
		return ("=");
	else if ((buff_stat->st_mode & S_IFMT) == S_IFWHT)
		return ("%");
	else if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
		return ("|");
	else
		return ("");
}

int		ft_len_name(t_list *files, char *toptions)
{
	int		len;

	if (toptions[o_q])
		len = ft_strlen(ft_str_name_q(files));
	else if (toptions[o_b] || toptions[o_B])
		len = ft_strlen(ft_str_name_b(files, toptions));
	else
		len = ft_strlen(((t_file*)files->content)->dirent.d_name);
	if (toptions[o_F])
		len++;
	return (len);
}

int		ft_color_index(char c)
{
	char	*addr;
	if ((addr = ft_strchr(g_colors, c)) != NULL)
		return (addr - g_colors);
	else
		return (18);
}

char	*ft_make_color_str(int index)
{
	char	*str;

	str = ft_strnew(10);
	ft_strcat(str, g_colors_tab[ft_color_index(lscolors[index * 2])]);
	ft_strcat(str, g_colors_tab[ft_color_index(ft_toupper(lscolors[index * 2 + 1]))]);
	return (str);
}

char	*ft_get_color(struct stat *buff_stat)
{

	if ((buff_stat->st_mode & S_IFMT) == S_IFDIR)
	{
		if ((buff_stat->st_mode & S_IWOTH) != 0)
		{
			if ((buff_stat->st_mode & S_ISVTX) != 0)
				return (ft_make_color_str(9));
			else
				return (ft_make_color_str(10));
		}
		else
			return (ft_make_color_str(0));
	}
	else if ((buff_stat->st_mode & S_IFMT) == S_IFLNK)
		return (ft_make_color_str(1));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFSOCK)
		return (ft_make_color_str(2));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
		return (ft_make_color_str(3));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFREG &&
			(buff_stat->st_mode & S_IXUSR) != 0)
	{
		if ((buff_stat->st_mode & S_ISUID) != 0)
			return (ft_make_color_str(7));
		else if ((buff_stat->st_mode & S_ISGID) != 0)
			return (ft_make_color_str(8));
		else
			return (ft_make_color_str(4));
	}
	else if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
		return (ft_make_color_str(5));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFCHR)
		return (ft_make_color_str(6));
	else
		return (ft_strdup("\x1b[39m\x1b[49m"));
}

char	*ft_str_name(t_list *files, char *toptions)
{
	char		*str;
	char		*name;
	struct stat	*buff_stat;

	buff_stat = &((t_file*)files->content)->stat;
	str = ft_strnew(ft_len_name(files, toptions) + toptions[o_F] + 20 * toptions[o_G]);
	str[0] = '\0';
	if (toptions[o_G])
		ft_strcat(str, ft_get_color(buff_stat));
	if (toptions[o_q])
		name = ft_str_name_q(files);
	else if (toptions[o_b] || toptions[o_B])
		name = ft_str_name_b(files, toptions);
	else
	{
		name = ft_strnew(ft_strlen(((t_file*)files->content)->dirent.d_name));
		ft_strcpy(name, ((t_file*)files->content)->dirent.d_name);
	}
	ft_strcat(str, name);
	if (toptions[o_G])
	{
		ft_strcat(str, g_colors_tab[ft_color_index('x')]);
		ft_strcat(str, g_colors_tab[ft_color_index('X')]);
	}
	if (toptions[o_F])
		ft_strcat(str, ft_f__str(buff_stat));
	else if (toptions[o_p] && (buff_stat->st_mode & S_IFMT) == S_IFDIR)
		ft_strcat(str, "/");
	return (str);
}

void	ft_display_name(t_list *files, char *toptions)
{
	char	*str;

	str = ft_str_name(files, toptions);
	ft_putstr(str);
	ft_strdel(&str);
}

void	ft_display_1(t_list *files, char *toptions)
{
	while (files != NULL)
	{
		if (toptions[o_i])
			ft_putino(files);
		ft_display_name(files, toptions);
		ft_putchar('\n');
		files = files->next;
	}
}

void	ft_display_m(t_list *files, char *toptions)
{
	while (files != NULL)
	{
		if (toptions[o_i])
			ft_putino(files);
		ft_display_name(files, toptions);
		files = files->next;
		if (files != NULL)
			ft_putstr(", ");
		else
			ft_putchar('\n');
	}
}

int		ft_get_max_len(t_list *files, char *toptions)
{
	int		max;
	int		tmp;
	int		ino_len;

	max = 0;
	while (files != NULL)
	{
		if (toptions[o_i])
			ino_len = ft_nbrsize(((t_file*)files->content)->stat.st_ino) + 1;
		else
			ino_len = 0;
		tmp = ft_len_name(files, toptions) + ino_len;
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

	max = ft_get_max_len(files, toptions);
	max = max + (8 - max % 8);
	nb_columns = g_columns / max;
	i = 0;
	while (files != NULL)
	{
		if (toptions[o_i])
			ft_putino(files);
		str = ft_str_name(files, toptions);
		len = ft_len_name(files, toptions);
		ft_putstr(str);
		ft_strdel(&str);
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

void	ft_display_c_(t_list *files, char *toptions)
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
	max = ft_get_max_len(files, toptions);
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
			len = ft_len_name(tab[j], toptions);
			ft_putstr(str);
			ft_strdel(&str);
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
	free(tab);
}

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

char	*ft_init_permission_str(void)
{
	char	*permissions;
	int		i;

	permissions = ft_strnew(10);
	i = 0;
	while (i < 9)
		permissions[i++] = '-';
	permissions[9] = ' ';
	permissions[10] = '\0';
	return (permissions);
}

char	*ft_permission_to_str(t_file *file)
{
	char		*permissions;
	struct stat	*buff_stat;

	buff_stat = &(file->stat);
	permissions = ft_init_permission_str();
	if ((buff_stat->st_mode & S_IRUSR) != 0)
		permissions[0] = 'r';
	if ((buff_stat->st_mode & S_IWUSR) != 0)
		permissions[1] = 'w';
	if ((buff_stat->st_mode & S_IXUSR) != 0)
		if ((buff_stat->st_mode & S_ISUID) != 0)
			permissions[2] = 's';
		else
			permissions[2] = 'x';
	else if ((buff_stat->st_mode & S_ISUID) != 0)
		permissions[2] = 'S';
	if ((buff_stat->st_mode & S_IRGRP) != 0)
		permissions[3] = 'r';
	if ((buff_stat->st_mode & S_IWGRP) != 0)
		permissions[4] = 'w';
	if ((buff_stat->st_mode & S_IXGRP) != 0)
		if ((buff_stat->st_mode & S_ISGID) != 0)
			permissions[5] = 's';
		else
			permissions[5] = 'x';
	else if ((buff_stat->st_mode & S_ISGID) != 0)
		permissions[5] = 'S';
	if ((buff_stat->st_mode & S_IROTH) != 0)
		permissions[6] = 'r';
	if ((buff_stat->st_mode & S_IWOTH) != 0)
		permissions[7] = 'w';
	if ((buff_stat->st_mode & S_IXOTH) != 0)
		if ((buff_stat->st_mode & S_ISVTX) != 0)
			permissions[8] = 't';
		else
			permissions[8] = 'x';
	else if ((buff_stat->st_mode & S_ISVTX) != 0)
		permissions[8] = 'T';
	if (file->xattrs != NULL)
		permissions[9] = '@';
	else if (file->acl != NULL)
		permissions[9] = '+';
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
	str = ft_strnew(size);
	ret = readlink(path, str, size);
	if (ret == -1)
	{
		exit(EXIT_FAILURE);
	}
	str[ret] = '\0';
	return (str);
}

void	print_date(struct stat *buff_stat, char *toptions)
{
	char			*str;

	if (toptions[o_c])
		str = ctime(&(buff_stat->st_ctimespec.tv_sec));
	else if (toptions[o_u])
		str = ctime(&(buff_stat->st_atimespec.tv_sec));
	else
		str = ctime(&(buff_stat->st_mtimespec.tv_sec));
	if (toptions[o_T])
		str[ft_strlen(str) - 1] = '\0';
	else
		str[ft_strlen(str) - 9] = '\0';
	ft_putstr(str + 4);
	ft_putchar(' ');
}

void	ft_display_l_file(t_list *file, t_column_sizes *cs, char *toptions)
{
	t_file		*file_content;
	struct stat	*buff_stat;
	char		*str;

	file_content = ((t_file*)file->content);
	buff_stat = &file_content->stat;
	if (toptions[o_i])
		ft_putino(file);
	ft_putchar(ft_type_to_char(buff_stat));
	ft_putstr(ft_permission_to_str(file_content));
	ft_putstr(" ");
	ft_putnbr_fixed(buff_stat->st_nlink, cs->nlink, 1);
	ft_putstr(" ");
	if (!toptions[o_g])
	{
		if (toptions[o_n])
			ft_putnbr_fixed(buff_stat->st_uid, cs->user, 0);
		else
			ft_putstr_fixed(getpwuid(buff_stat->st_uid)->pw_name, cs->user, 0);
		ft_putstr("  ");
	}
	if (!toptions[o_o])
	{
		if (toptions[o_n])
			ft_putnbr_fixed(buff_stat->st_gid, cs->group, 0);
		else
			ft_putstr_fixed(getgrgid(buff_stat->st_gid)->gr_name, cs->group, 0);
		ft_putstr("  ");
	}
	ft_putnbr_fixed(buff_stat->st_size, cs->size, 1);
	ft_putstr(" ");
	print_date(buff_stat, toptions);
	ft_display_name(file, toptions);
	if (ft_type_to_char(buff_stat) == 'l')
	{
		ft_putstr(" -> ");
		str = make_path(file_content->path, file_content->dirent.d_name);
		ft_putstr(link_to_str(str, buff_stat));
		free(str);
	}
	ft_putchar('\n');
	if (toptions[o_at])
		ft_display_xattrs(file_content);
	if (toptions[o_e])
		ft_display_acls(file_content);
}

long long int	ft_get_total(t_list *files)
{
	long long int	total;

	total = 0;
	while (files != NULL)
	{
		total += ((t_file*)files->content)->stat.st_blocks
			* (((t_file*)files->content)->stat.st_blksize / 4096);
		files = files->next;
	}
	return (total);
}

void	ft_display_l(t_list *files, char *toptions)
{
	t_column_sizes	*column_sizes;
	long long int	total;

	column_sizes = ft_get_column_size(files, toptions);
	if (!toptions[o_d] && files != NULL && files->next != NULL)
	{
		total = ft_get_total(files);
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
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

t_column_sizes	*ft_new_column_sizes(void)
{
	t_column_sizes	*column_sizes;

	if (!(column_sizes = (t_column_sizes*)malloc(sizeof(t_column_sizes))))
		exit(1);
	column_sizes->nlink = 0;
	column_sizes->size = 0;
	column_sizes->user = 0;
	column_sizes->group = 0;
	return (column_sizes);
}

t_column_sizes	*ft_get_column_size(t_list *files, char *toptions)
{
	int				tmp;
	t_column_sizes	*cs;

	cs = ft_new_column_sizes();
	while (files != NULL)
	{
		tmp = ft_nbrsize(((t_file*)files->content)->stat.st_nlink);
		cs->nlink = cs->nlink < tmp ? tmp : cs->nlink;
		tmp = ft_nbrsize(((t_file*)files->content)->stat.st_size);
		cs->size = cs->size < tmp ? tmp : cs->size;
		if (toptions[o_n])
			tmp = ft_nbrsize(((t_file*)files->content)->stat.st_uid);
		else
			tmp = ft_strlen(getpwuid(((t_file*)files->content)->
						stat.st_uid)->pw_name);
		cs->user = cs->user < tmp ? tmp : cs->user;
		if (toptions[o_n])
			tmp = ft_nbrsize(((t_file*)files->content)->stat.st_gid);
		else
			tmp = ft_strlen(getgrgid(((t_file*)files->content)
						->stat.st_gid)->gr_name);
		cs->group = cs->group < tmp ? tmp : cs->group;
		files = files->next;
	}
	return (cs);
}

void	ft_displayls(t_list *files, char *toptions)
{
	if (toptions[o_l])
		ft_display_l(files, toptions);
	else if (toptions[o_x])
		ft_display_x(files, toptions);
	else if (toptions[o_C])
		ft_display_c_(files, toptions);
	else if (toptions[o_m])
		ft_display_m(files, toptions);
	else
		ft_display_1(files, toptions);
}
