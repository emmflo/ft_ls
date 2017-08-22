/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:02:02 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/19 18:18:21 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*check_malloc(void *ptr)
{
	if (!ptr)
	{
		ft_putstr_fd("ls: malloc error\n", 2);
		exit(1);
	}
	return (ptr);
}

void	opt_error(char option)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putstr_fd("\nusage: ls [-@1AaCcdeFfGgHiLlmnOoPpRrSsTtuUx]", 2);
	ft_putstr_fd(" [file ...]\n", 2);
	exit(1);
}

int		ft_check_errno(char *pre)
{
	if (errno != 0)
	{
		ft_print_errno(pre);
		return (-1);
	}
	return (0);
}

void	ft_print_errno(char *pre)
{
	ft_print_error(pre, strerror(errno));
}

void	ft_print_error(char *pre, char *error)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(pre, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
}
