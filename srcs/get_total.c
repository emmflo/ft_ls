/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_total.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:40:16 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:41:49 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long long int	ft_get_size(t_file *file)
{
	return (file->stat.st_blocks);
}

long long int	ft_get_total(t_list *files)
{
	long long int	total;

	total = 0;
	while (files != NULL)
	{
		total += ft_get_size(((t_file*)files->content));
		files = files->next;
	}
	return (total);
}
