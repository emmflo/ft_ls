/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:19:10 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/19 15:30:19 by eflorenz         ###   ########.fr       */
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
		pos += len;
		if (pos > g_columns) 
		{
			pos = len;
			ft_putchar('\n');
		}
		free(str);
		if (g_toptions[o_i])
			ft_putino(files, cs);
		ft_putstr(str);
		files = files->next;
		if (files != NULL)
			ft_putstr(", ");
		else
			ft_putchar('\n');
	}
}
