/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:27:34 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/19 13:01:52 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_date_t(long t)
{
	char	*str;

	str = ctime(&t);
	str[ft_strlen(str) - 1] = '\0';
	ft_putstr(str + 4);
	ft_putchar(' ');
	//ft_strdel(&str);
}

void	print_date_(long t)
{
	char	*str;
	long	now;
	int		six_month;

	now = time(NULL);
	str = ctime(&t);
	six_month = ((t + 15768000) <= now) || t > now;
	if (!six_month)
		str[ft_strlen(str) - 9] = '\0';
	else
	{
		str[ft_strlen(str) - 1] = '\0';
		str[ft_strlen(str) - 14] = '\0';
	}
	ft_putstr(str + 4);
	if (six_month)
	{
		ft_putstr("  ");
		ft_putstr(str + 20);
	}
	ft_putchar(' ');
	//ft_strdel(&str);
}

void	print_date(struct stat *buff_stat)
{
	long			t;

	if (g_toptions[o_c])
		t = (buff_stat->st_ctimespec.tv_sec);
	else if (g_toptions[o_U])
		t = (buff_stat->st_birthtimespec.tv_sec);
	else if (g_toptions[o_u])
		t = (buff_stat->st_atimespec.tv_sec);
	else
		t = (buff_stat->st_mtimespec.tv_sec);
	if (g_toptions[o_T])
		print_date_t(t);
	else
		print_date_(t);
}
