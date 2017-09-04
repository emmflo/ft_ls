/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:58:29 by eflorenz          #+#    #+#             */
/*   Updated: 2017/09/04 22:53:10 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	free(cs);
}
