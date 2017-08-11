/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:02:51 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:11:00 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putnbr_fixed(int nb, int column_size, int right)
{
	column_size -= ft_nbrsize(nb);
	if (!right)
		ft_putnbr(nb);
	while (column_size > 0)
	{
		ft_putchar(' ');
		column_size--;
	}
	if (right)
		ft_putnbr(nb);
}

void	ft_putstr_fixed(char *str, int column_size, int right)
{
	column_size -= ft_strlen(str);
	if (!right)
		ft_putstr(str);
	while (column_size > 0)
	{
		ft_putchar(' ');
		column_size--;
	}
	if (right)
		ft_putstr(str);
}

int		ft_len_name(t_list *files, t_column_sizes *cs)
{
	int		len;

	if (g_toptions[o_q])
		len = ft_strlen(ft_str_name_q(files));
	else if (g_toptions[o_b] || g_toptions[o_B])
		len = ft_strlen(ft_str_name_b(files));
	else
		len = ft_strlen(((t_file*)files->content)->dirent.d_name);
	if (g_toptions[o_F])
		len++;
	if (g_toptions[o_i])
		len += cs->ino + 1;
	return (len);
}

int		ft_get_max_len(t_list *files, t_column_sizes *cs)
{
	int		max;
	int		tmp;

	max = 0;
	while (files != NULL)
	{
		tmp = ft_len_name(files, cs);
		max = tmp > max ? tmp : max;
		files = files->next;
	}
	return (max);
}

void	ft_putnchar(char c, int nb)
{
	int	i;

	i = 0;
	while (i++ < nb)
		ft_putchar(c);
}
