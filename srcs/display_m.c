/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:19:10 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:19:20 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
