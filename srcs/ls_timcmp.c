/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_timcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:03:49 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 03:03:55 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_sortfiles_bytime(t_list *files)
{
	if (g_toptions[o_c])
		return (ft_sortfiles_bytime_c(files));
	else if (g_toptions[o_u])
		return (ft_sortfiles_bytime_u(files));
	else if (g_toptions[o_U])
		return (ft_sortfiles_bytime_b(files));
	else
		return (ft_sortfiles_bytime_m(files));
}

int		ft_st_timcmp(struct timespec *a, struct timespec *b)
{
	if (a->tv_sec < b->tv_sec)
		return (1);
	else if (a->tv_sec > b->tv_sec)
		return (-1);
	else
	{
		if (a->tv_nsec < b->tv_nsec)
			return (1);
		else if (a->tv_nsec > b->tv_nsec)
			return (-1);
		else
			return (0);
		return (ft_d_namecmp(a, b));
	}
}
