/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 00:41:14 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:40:06 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
