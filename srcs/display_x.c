/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:02:06 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:02:18 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
