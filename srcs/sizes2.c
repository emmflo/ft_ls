/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:48:43 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:49:20 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_get_ino_size(t_file *file)
{
	return (ft_nbrsize(file->stat.st_ino));
}

int	ft_get_size_size(t_file *file)
{
	return (ft_nbrsize(file->stat.st_size));
}

int	ft_get_flags_size(t_file *file)
{
	return (ft_strlen(fflagstostr(file->stat.st_flags)));
}

int	ft_get_s_size(t_file *file)
{
	return (ft_nbrsize(ft_get_size(file)));
}
