/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:02:51 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/19 19:03:30 by eflorenz         ###   ########.fr       */
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

int		ft_len_name(char *name, t_column_sizes *cs)
{
	int		len;

	len = ft_strlen(name);
	if (g_toptions[o_i])
		len += cs->ino + 1;
	if (g_toptions[o_s])
		len += cs->s + 1;
	return (len);
}

int		ft_get_max_len(t_list *files, t_column_sizes *cs)
{
	int		max;
	int		tmp;
	char	*name;

	max = 0;
	while (files != NULL)
	{
		name = ft_str_name(files, cs);
		tmp = ft_len_name(name, cs);
		max = tmp > max ? tmp : max;
		files = files->next;
		ft_strdel(&name);
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
