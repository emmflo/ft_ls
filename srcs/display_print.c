/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 00:51:44 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:27:28 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putino(t_list *files, t_column_sizes *cs)
{
	ft_putnbr_fixed(((t_file*)files->content)->stat.st_ino, cs->ino, 1);
	ft_putchar(' ');
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

void	ft_display_name(t_list *files, t_column_sizes *cs)
{
	char	*str;

	str = ft_str_name(files, cs);
	ft_putstr(str);
	ft_strdel(&str);
}
