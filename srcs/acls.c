/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:11:51 by eflorenz          #+#    #+#             */
/*   Updated: 2017/04/14 13:39:27 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_acls(t_file *file)
{
	char	*path;
	char	*acl_text;
	acl_t	acl;

	path = make_path(file->path, file->dirent.d_name);
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	file->acl = acl_dup(acl);
}

void	ft_display_acls(t_file *file)
{
	ssize_t	len;
	char	*acl_text;

	acl_text = acl_to_text(file->acl, &len);
	ft_putstr(acl_text);
}
