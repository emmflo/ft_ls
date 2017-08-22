/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_permissions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:43:06 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:44:43 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_init_permission_str(void)
{
	char	*permissions;
	int		i;

	check_malloc(permissions = ft_strnew(10));
	i = 0;
	while (i < 9)
		permissions[i++] = '-';
	permissions[9] = ' ';
	permissions[10] = '\0';
	return (permissions);
}

char	*ft_permission_to_str(t_file *file)
{
	char		*permissions;
	struct stat	*buff_stat;

	buff_stat = &(file->stat);
	permissions = ft_init_permission_str();
	ft_permission_user(permissions, buff_stat);
	ft_permission_group(permissions, buff_stat);
	ft_permission_other(permissions, buff_stat);
	ft_permission_extra(permissions, file);
	return (permissions);
}
