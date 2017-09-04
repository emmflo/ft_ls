/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 00:36:22 by eflorenz          #+#    #+#             */
/*   Updated: 2017/09/04 22:39:07 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_get_user_size(t_file *file)
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

int		ft_get_nlink_size(t_file *file)
{
	return (ft_nbrsize(file->stat.st_nlink));
}

int		ft_get_group_size(t_file *file)
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

void	ft_print_total(t_list *files)
{
	long long int	total;

	total = ft_get_total(files);
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}
