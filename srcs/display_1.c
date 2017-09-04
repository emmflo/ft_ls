/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:14:12 by eflorenz          #+#    #+#             */
/*   Updated: 2017/09/04 20:36:18 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_1(t_list *files, t_column_sizes *cs)
{
	if (g_toptions[o_s] && !g_toptions[o_d])
		ft_print_total(files);
	while (files != NULL)
	{
		if (g_toptions[o_i])
			ft_putino(files, cs);
		if (g_toptions[o_s])
			ft_putsize(files, cs);
		ft_display_name(files, cs);
		ft_putchar('\n');
		files = files->next;
	}
}
