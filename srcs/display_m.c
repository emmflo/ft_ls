/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:19:10 by eflorenz          #+#    #+#             */
/*   Updated: 2017/09/04 22:36:40 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_m(t_list *files, t_column_sizes *cs)
{
	char	*str;
	int		pos;
	int		len;

	pos = 0;
	while (files != NULL)
	{
		str = ft_str_name(files, cs);
		len = ft_len_name(str, cs);
		pos += len + 2;
		if (pos > g_columns)
		{
			pos = len + 2;
			ft_putchar('\n');
		}
		if (g_toptions[o_i])
			ft_putino(files, cs);
		if (g_toptions[o_s])
			ft_putsize(files, cs);
		ft_putstr(str);
		free(str);
		files = files->next;
		ft_putstr(files != NULL ? ", " : "\n");
	}
}
