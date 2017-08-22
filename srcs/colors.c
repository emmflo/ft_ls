/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:21:01 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:31:02 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_color_name_start(char *str, struct stat *buff_stat)
{
	char	*tmp;

	if (g_toptions[o_G])
	{
		tmp = ft_get_color(buff_stat);
		ft_strcat(str, tmp);
		ft_strdel(&tmp);
	}
}

void	ft_color_name_end(char *str)
{
	if (g_toptions[o_G])
	{
		ft_strcat(str, g_colors_tab[ft_color_index('x')]);
		ft_strcat(str, g_colors_tab[ft_color_index('X')]);
	}
}

int		ft_color_index(char c)
{
	char	*addr;

	if ((addr = ft_strchr(g_colors, c)) != NULL)
		return (addr - g_colors);
	else
		return (18);
}

char	*ft_make_color_str(int index)
{
	char	*str;

	check_malloc(str = ft_strnew(10));
	ft_strcat(str, g_colors_tab[ft_color_index(g_lscolors[index * 2])]);
	ft_strcat(str, g_colors_tab[ft_color_index(ft_toupper(
					g_lscolors[index * 2 + 1]))]);
	return (str);
}
