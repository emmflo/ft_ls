/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 00:30:47 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 00:35:27 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_set_max(int *a, int tmp)
{
	*a = *a < tmp ? tmp : *a;
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
