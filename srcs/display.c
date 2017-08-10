/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:58:29 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/10 20:38:03 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <stdlib.h>

extern int	g_columns;
extern char	*g_colors;
extern char	g_colors_tab[][6];
extern char	*g_lscolors;

char	*ft_itoa(int nb);

void	ft_putino(t_list *files, t_column_sizes *cs)
{
	ft_putnbr_fixed(((t_file*)files->content)->stat.st_ino, cs->ino, 1);
	ft_putchar(' ');
}

char	ft_f__char(struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_IFMT) == S_IFDIR)
		return ('/');
	else if ((buff_stat->st_mode & S_IFMT) == S_IFREG &&
			(buff_stat->st_mode & S_IXUSR) != 0)
		return ('*');
	else if ((buff_stat->st_mode & S_IFMT) == S_IFLNK)
		return ('@');
	else if ((buff_stat->st_mode & S_IFMT) == S_IFSOCK)
		return ('=');
	else if ((buff_stat->st_mode & S_IFMT) == S_IFWHT)
		return ('%');
	else if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
		return ('|');
	else
		return ('\0');
}

int		ft_len_name(t_list *files, t_column_sizes *cs)
{
	int		len;

	if (g_toptions[o_q])
		len = ft_strlen(ft_str_name_q(files));
	else if (g_toptions[o_b] || g_toptions[o_B])
		len = ft_strlen(ft_str_name_b(files));
	else
		len = ft_strlen(((t_file*)files->content)->dirent.d_name);
	if (g_toptions[o_F])
		len++;
	if (g_toptions[o_i])
		len += cs->ino + 1;
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
	ft_strcat(str, g_colors_tab[ft_color_index(g_lscolors[index * 2])]);
	ft_strcat(str, g_colors_tab[ft_color_index(ft_toupper(
					g_lscolors[index * 2 + 1]))]);
	return (str);
}

char	*ft_get_color_dir(struct stat *buff_stat)
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

char	*ft_get_color_reg_file(struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_ISUID) != 0)
		return (ft_make_color_str(7));
	else if ((buff_stat->st_mode & S_ISGID) != 0)
		return (ft_make_color_str(8));
	else
		return (ft_make_color_str(4));
}

char	*ft_get_color(struct stat *buff_stat)
{
	if ((buff_stat->st_mode & S_IFMT) == S_IFDIR)
		return (ft_get_color_dir(buff_stat));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFLNK)
		return (ft_make_color_str(1));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFSOCK)
		return (ft_make_color_str(2));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
		return (ft_make_color_str(3));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFREG &&
			(buff_stat->st_mode & S_IXUSR) != 0)
		return (ft_get_color_reg_file(buff_stat));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFIFO)
		return (ft_make_color_str(5));
	else if ((buff_stat->st_mode & S_IFMT) == S_IFCHR)
		return (ft_make_color_str(6));
	else
		return (ft_strdup("\x1b[39m\x1b[49m"));
}

void	ft_color_name_start(char *str, struct stat *buff_stat)
{
	char	*tmp;

	if (g_toptions[o_G])
	{
		tmp = ft_get_color(buff_stat);
		ft_strcat(str, tmp);
		ft_strdel(&tmp);
	}
}

char	*ft_str_name_(t_list *files)
{
	char	*name;

	name = ft_strnew(ft_strlen(((t_file*)files->content)->dirent.d_name));
	ft_strcpy(name, ((t_file*)files->content)->dirent.d_name);
	return (name);
}

void	ft_color_name_end(char *str)
{
	if (g_toptions[o_G])
	{
		ft_strcat(str, g_colors_tab[ft_color_index('x')]);
		ft_strcat(str, g_colors_tab[ft_color_index('X')]);
	}
}

char	*ft_str_name(t_list *files, t_column_sizes *cs)
{
	char		*str;
	char		*name;
	struct stat	*buff_stat;

	buff_stat = &((t_file*)files->content)->stat;
	str = ft_strnew(ft_len_name(files, cs)
			+ g_toptions[o_F] + g_toptions[o_p] + 20 * g_toptions[o_G]);
	str[0] = '\0';
	ft_color_name_start(str, buff_stat);
	if (g_toptions[o_q])
		name = ft_str_name_q(files);
	else if (g_toptions[o_b] || g_toptions[o_B])
		name = ft_str_name_b(files);
	else
		name = ft_str_name_(files);
	ft_strcat(str, name);
	free(name);
	ft_color_name_end(str);
	str[ft_strlen(str) + 1] = '\0';
	if (g_toptions[o_F])
		str[ft_strlen(str)] = ft_f__char(buff_stat);
	else if (g_toptions[o_p] && (buff_stat->st_mode & S_IFMT) == S_IFDIR)
		ft_strcat(str, "/");
	return (str);
}

void	ft_display_name(t_list *files, t_column_sizes *cs)
{
	char	*str;

	str = ft_str_name(files, cs);
	ft_putstr(str);
	ft_strdel(&str);
}

void	ft_display_1(t_list *files, t_column_sizes *cs)
{
	while (files != NULL)
	{
		if (g_toptions[o_i])
			ft_putino(files, cs);
		ft_display_name(files, cs);
		ft_putchar('\n');
		files = files->next;
	}
}

void	ft_display_m(t_list *files, t_column_sizes *cs)
{
	while (files != NULL)
	{
		if (g_toptions[o_i])
			ft_putino(files, cs);
		ft_display_name(files, cs);
		files = files->next;
		if (files != NULL)
			ft_putstr(", ");
		else
			ft_putchar('\n');
	}
}

int		ft_get_max_len(t_list *files, t_column_sizes *cs)
{
	int		max;
	int		tmp;

	max = 0;
	while (files != NULL)
	{
		tmp = ft_len_name(files, cs);
		max = tmp > max ? tmp : max;
		files = files->next;
	}
	return (max);
}

void	ft_putnchar(char c, int nb)
{
	int	i;

	i = 0;
	while (i++ < nb)
		ft_putchar(c);
}

void	ft_print_x(t_list *files, t_column_sizes *cs, int max, int nb_columns)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	while (files != NULL)
	{
		if (g_toptions[o_i])
			ft_putino(files, cs);
		str = ft_str_name(files, cs);
		len = ft_len_name(files, cs);
		ft_putstr(str);
		ft_strdel(&str);
		if (len % 8 != 0)
			ft_putchar('\t');
		ft_putnchar('\t', (max - len) / 8);
		if (i++ % nb_columns == nb_columns - 1)
			ft_putchar('\n');
		files = files->next;
	}
	if (i % nb_columns != 0)
		ft_putchar('\n');
}

void	ft_display_x(t_list *files, t_column_sizes *cs)
{
	int		max;
	int		nb_columns;

	max = ft_get_max_len(files, cs);
	max = max + (8 - max % 8);
	nb_columns = g_columns / max;
	ft_print_x(files, cs, max, nb_columns);
}

t_list	**ft_make_file_tab(t_list *files)
{
	t_list	**tab;
	int		len;
	int		i;

	len = ft_lstlen(files);
	if (!(tab = malloc(sizeof(t_list*) * len)))
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

int		ft_get_nb_lines_c_(int max, int tab_len)
{
	int		nb_columns;
	int		nb_lines;

	nb_columns = g_columns / max;
	nb_lines = tab_len / nb_columns + (tab_len % nb_columns != 0);
	return (nb_lines);
}

void	ft_print_c_(int j, t_tab *tab, int nb_lines, int max,
		t_column_sizes *cs)
{
	char	*str;
	int		len;

	while (j < tab->tab_len)
	{
		if (g_toptions[o_i])
			ft_putino(tab->tab[j], cs);
		str = ft_str_name(tab->tab[j], cs);
		len = ft_len_name(tab->tab[j], cs);
		ft_putstr(str);
		ft_strdel(&str);
		if (len % 8 != 0)
			ft_putchar('\t');
		if (j < tab->tab_len - 1)
			ft_putnchar('\t', (max - len) / 8);
		j += nb_lines;
	}
}

void	ft_display_c_(t_list *files, t_column_sizes *cs)
{
	t_tab	tab;
	int		max;
	int		i;
	int		nb_lines;

	tab.tab = (void**)ft_make_file_tab(files);
	tab.tab_len = ft_lstlen(files);
	max = ft_get_max_len(files, cs);
	max = max + (8 - max % 8);
	nb_lines = ft_get_nb_lines_c_(max, tab.tab_len);
	i = 0;
	while (i < nb_lines)
	{
		ft_print_c_(i, &tab, nb_lines, max, cs);
		i++;
		ft_putchar('\n');
	}
	free(tab.tab);
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

void	ft_permission_user(char *permissions, struct stat *buff_stat)
{
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
}

void	ft_permission_group(char *permissions, struct stat *buff_stat)
{
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
}

void	ft_permission_other(char *permissions, struct stat *buff_stat)
{
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
}

void	ft_permission_extra(char *permissions, t_file *file)
{
	if (file->xattrs_buffsize > 0)
		permissions[9] = '@';
	else if (file->acl != NULL)
		permissions[9] = '+';
}

char	*ft_permission_to_str(t_file *file)
{
	char		*permissions;
	struct stat	*buff_stat;

	buff_stat = &(file->stat);
	permissions = ft_init_permission_str();
	ft_permission_user(permissions, buff_stat);
	ft_permission_group(permissions, buff_stat);
	ft_permission_other(permissions, buff_stat);
	ft_permission_extra(permissions, file);
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

int		ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

void	print_date_t(long t)
{
	char	*str;
	long	now;

	now = time(NULL);
	str = ctime(&t);
	str[ft_strlen(str) - 1] = '\0';
	ft_putstr(str + 4);
	ft_putchar(' ');
}

void	print_date_(long t)
{
	char	*str;
	long	now;
	int		six_month;

	now = time(NULL);
	str = ctime(&t);
	six_month = ((t + 15768000) <= now) || t > now;
	if (!six_month)
		str[ft_strlen(str) - 9] = '\0';
	else
	{
		str[ft_strlen(str) - 1] = '\0';
		str[ft_strlen(str) - 14] = '\0';
	}
	ft_putstr(str + 4);
	if (six_month)
	{
		ft_putstr("  ");
		ft_putstr(str + 20);
	}
	ft_putchar(' ');
}

void	print_date(struct stat *buff_stat)
{
	long			t;

	if (g_toptions[o_c])
		t = (buff_stat->st_ctimespec.tv_sec);
	else if (g_toptions[o_U])
		t = (buff_stat->st_birthtimespec.tv_sec);
	else if (g_toptions[o_u])
		t = (buff_stat->st_atimespec.tv_sec);
	else
		t = (buff_stat->st_mtimespec.tv_sec);
	if (g_toptions[o_T])
		print_date_t(t);
	else
		print_date_(t);
}

void	ft_print_perm_and_type(t_file *file_content, struct stat *buff_stat)
{
	char	*str;

	ft_putchar(ft_type_to_char(buff_stat));
	str = ft_permission_to_str(file_content);
	ft_putstr(str);
	ft_strdel(&str);
}

void	ft_print_group_and_user(struct stat *buff_stat, t_column_sizes *cs)
{
	if (!g_toptions[o_g])
	{
		if (g_toptions[o_n])
			ft_putnbr_fixed(buff_stat->st_uid, cs->user, 0);
		else
			ft_putstr_fixed(getpwuid(buff_stat->st_uid)->pw_name, cs->user, 0);
		ft_putstr("  ");
	}
	if (!g_toptions[o_o])
	{
		if (g_toptions[o_n])
			ft_putnbr_fixed(buff_stat->st_gid, cs->group, 0);
		else
			ft_putstr_fixed(getgrgid(buff_stat->st_gid)->gr_name, cs->group, 0);
		ft_putstr("  ");
	}
	if (g_toptions[o_o] && g_toptions[o_g])
		ft_putstr("  ");
}

void	ft_display_l_file_first_part(t_list *file, t_column_sizes *cs,
		struct stat *buff_stat, t_file *file_content)
{
	if (g_toptions[o_i])
		ft_putino(file, cs);
	ft_print_perm_and_type(file_content, buff_stat);
	ft_putstr(" ");
	ft_putnbr_fixed(buff_stat->st_nlink, cs->nlink, 1);
	ft_putstr(" ");
	ft_print_group_and_user(buff_stat, cs);
}

void	ft_display_l_file_second_part(t_column_sizes *cs,
		struct stat *buff_stat)
{
	if (g_toptions[o_O])
	{
		if (buff_stat->st_flags != 0)
			ft_putstr_fixed(fflagstostr(buff_stat->st_flags), cs->flags, 0);
		else
			ft_putstr_fixed("-", cs->flags, 0);
		ft_putstr(" ");
	}
	ft_putnbr_fixed(buff_stat->st_size, cs->size, 1);
	ft_putstr(" ");
	print_date(buff_stat);
}

void	ft_display_l_file_third_part(t_list *file, t_column_sizes *cs,
		struct stat *buff_stat, t_file *file_content)
{
	char		*str;

	ft_display_name(file, cs);
	if (ft_type_to_char(buff_stat) == 'l')
	{
		ft_putstr(" -> ");
		str = make_path(file_content->path, file_content->dirent.d_name);
		ft_putstr(link_to_str(str, buff_stat));
		free(str);
	}
	ft_putchar('\n');
	if (g_toptions[o_at])
		ft_display_xattrs(file_content);
	if (g_toptions[o_e])
		ft_display_acls(file_content);
}

void	ft_display_l_file(t_list *file, t_column_sizes *cs)
{
	t_file		*file_content;
	struct stat	*buff_stat;

	file_content = ((t_file*)file->content);
	buff_stat = &file_content->stat;
	ft_display_l_file_first_part(file, cs, buff_stat, file_content);
	ft_display_l_file_second_part(cs, buff_stat);
	ft_display_l_file_third_part(file, cs, buff_stat, file_content);
}

long long int	ft_get_size(t_file *file)
{
	return (file->stat.st_blocks);
}

long long int	ft_get_total(t_list *files)
{
	long long int	total;

	total = 0;
	while (files != NULL)
	{
		total += ft_get_size(((t_file*)files->content));
		files = files->next;
	}
	return (total);
}

void	ft_display_l(t_list *files, t_column_sizes *cs)
{
	long long int	total;

	if (!g_toptions[o_d] && files != NULL)
	{
		total = ft_get_total(files);
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
	while (files != NULL)
	{
		ft_display_l_file(files, cs);
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
	column_sizes->flags = 1;
	column_sizes->s = 0;
	column_sizes->ino = 0;
	return (column_sizes);
}

int				ft_get_user_size(t_file *file)
{
	int				size;
	struct passwd	*pass;

	if (g_toptions[o_n])
		size = ft_nbrsize(file->stat.st_uid);
	else
	{
		pass = getpwuid(file->stat.st_uid);
		size = ft_strlen(pass->pw_name);
	}
	return (size);
}

int				ft_get_nlink_size(t_file *file)
{
	return (ft_nbrsize(file->stat.st_nlink));
}

int				ft_get_group_size(t_file *file)
{
	int				size;
	struct group	*group;

	if (g_toptions[o_n])
		size = ft_nbrsize(file->stat.st_gid);
	else
	{
		group = getgrgid(file->stat.st_gid);
		size = ft_strlen(group->gr_name);
	}
	return (size);
}

int				ft_get_ino_size(t_file *file)
{
	return (ft_nbrsize(file->stat.st_ino));
}

int				ft_get_size_size(t_file *file)
{
	return (ft_nbrsize(file->stat.st_size));
}

int				ft_get_flags_size(t_file *file)
{
	return (ft_strlen(fflagstostr(file->stat.st_flags)));
}

int				ft_get_s_size(t_file *file)
{
	return (ft_nbrsize(ft_get_size(file)));
}

void			ft_set_max(int *a, int tmp)
{
	*a = *a < tmp ? tmp : *a;
}

t_column_sizes	*ft_get_column_size(t_list *files)
{
	t_file			*file;
	t_column_sizes	*cs;

	cs = ft_new_column_sizes();
	while (files != NULL)
	{
		file = ((t_file*)files->content);
		ft_set_max(&(cs->ino), ft_get_ino_size(file));
		if (g_toptions[o_l])
		{
			ft_set_max(&(cs->nlink), ft_get_nlink_size(file));
			ft_set_max(&(cs->size), ft_get_size_size(file));
			ft_set_max(&(cs->user), ft_get_user_size(file));
			ft_set_max(&(cs->group), ft_get_group_size(file));
		}
		if (g_toptions[o_O])
			ft_set_max(&(cs->flags), ft_get_flags_size(file));
		if (g_toptions[o_s])
			ft_set_max(&(cs->s), ft_get_s_size(file));
		files = files->next;
	}
	return (cs);
}

void	ft_displayls(t_list *files)
{
	t_column_sizes	*cs;

	cs = ft_get_column_size(files);
	if (g_toptions[o_l])
		ft_display_l(files, cs);
	else if (g_toptions[o_x])
		ft_display_x(files, cs);
	else if (g_toptions[o_C])
		ft_display_c_(files, cs);
	else if (g_toptions[o_m])
		ft_display_m(files, cs);
	else
		ft_display_1(files, cs);
}
