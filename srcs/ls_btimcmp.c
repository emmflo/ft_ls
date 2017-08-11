/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_btimcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:01:34 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 03:01:40 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_sortfiles_bytime_b(t_list *files)
{
	if (g_toptions[o_r])
		return (ft_merge_sort(files, &ft_st_btimcmp_r));
	else
		return (ft_merge_sort(files, &ft_st_btimcmp));
}

int		ft_st_btimcmp(void *a, void *b)
{
	int				ret;
	struct stat		*stat1;
	struct stat		*stat2;

	stat1 = &((t_file*)a)->stat;
	stat2 = &((t_file*)b)->stat;
	ret = ft_st_timcmp(&stat1->st_birthtimespec, &stat2->st_birthtimespec);
	if (ret == 0)
		return (ft_d_namecmp(a, b));
	else
		return (ret);
}

int		ft_st_btimcmp_r(void *a, void *b)
{
	return (ft_st_btimcmp(b, a));
}
