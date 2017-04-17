/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:11:51 by eflorenz          #+#    #+#             */
/*   Updated: 2017/04/17 16:36:29 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_acls(t_file *file)
{
	char	*path;
	acl_t	acl;

	path = make_path(file->path, file->dirent.d_name);
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	file->acl = acl_dup(acl);
}

void	ft_display_acls(t_file *file)
{
	ssize_t	len;
	int		i;
	char	*acl_text;
	char	**acl_lines;
	char	**acl_fields;

	if (file->acl == NULL)
		return ;
	acl_text = acl_to_text(file->acl, &len);
	acl_lines = ft_strsplit(acl_text, '\n');
	i = 1;
	while (acl_lines[i] != NULL)
	{
		acl_fields = ft_strsplit(acl_lines[i], ':');
		ft_putnbr_fixed(i - 1, 2, 1);
		ft_putstr(": ");
		ft_putstr(acl_fields[0]);
		ft_putchar(':');
		ft_putstr(acl_fields[2]);
		ft_putchar(' ');
		ft_putstr(acl_fields[4]);
		ft_putchar(' ');
		ft_putstr(acl_fields[5]);
		ft_putchar('\n');
		i++;
	}
	//ft_putstr(acl_text);
}
