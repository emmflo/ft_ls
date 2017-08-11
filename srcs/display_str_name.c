/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:04:52 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 02:25:04 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <ctype.h>

char	*ft_str_name_(t_list *files)
{
	char	*name;

	name = ft_strnew(ft_strlen(((t_file*)files->content)->dirent.d_name));
	ft_strcpy(name, ((t_file*)files->content)->dirent.d_name);
	return (name);
}

char	*ft_str_name(t_list *files, t_column_sizes *cs)
{
	char		*str;
	char		*name;
	struct stat	*buff_stat;

	buff_stat = &((t_file*)files->content)->stat;
	str = ft_strnew(ft_len_name(files, cs)
			+ g_toptions[o_F] + g_toptions[o_p] + 20 * g_toptions[o_G]);
	str[0] = '\0';
	ft_color_name_start(str, buff_stat);
	if (g_toptions[o_q])
		name = ft_str_name_q(files);
	else if (g_toptions[o_b] || g_toptions[o_B])
		name = ft_str_name_b(files);
	else
		name = ft_str_name_(files);
	ft_strcat(str, name);
	free(name);
	ft_color_name_end(str);
	str[ft_strlen(str) + 1] = '\0';
	if (g_toptions[o_F])
		str[ft_strlen(str)] = ft_f__char(buff_stat);
	else if (g_toptions[o_p] && (buff_stat->st_mode & S_IFMT) == S_IFDIR)
		ft_strcat(str, "/");
	return (str);
}

char	*ft_str_name_q(t_list *files)
{
	char	*ptr;
	char	*str;
	int		i;

	str = ft_strnew(ft_strlen(((t_file*)files->content)->dirent.d_name) + 1);
	ptr = ((t_file*)files->content)->dirent.d_name;
	i = 0;
	while (*ptr != '\0')
	{
		if (isgraph(*ptr))
			str[i++] = *ptr;
		else
			str[i++] = '?';
		ptr++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_str_name_b_loop(char *ptr, char *str, int *i)
{
	char	*tmp;

	if (isprint(*ptr))
		str[(*i)++] = *ptr;
	else if (g_toptions[o_b] && ft_escape(*ptr))
	{
		str[*i] = '\\';
		str[*i + 1] = ft_char_to_escape(*ptr);
		*i += 2;
	}
	else
	{
		str[*i] = '\\';
		str[*i + 1] = '\0';
		tmp = ft_char_to_oct(*ptr);
		ft_strcat(str, tmp);
		free(tmp);
		*i += 4;
	}
}

char	*ft_str_name_b(t_list *files)
{
	char	*ptr;
	char	*str;
	int		i;

	str = ft_strnew(ft_get_name_size_b(files) + 1);
	ptr = ((t_file*)files->content)->dirent.d_name;
	i = 0;
	while (*ptr != '\0')
	{
		ft_str_name_b_loop(ptr, str, &i);
		ptr++;
	}
	str[i] = '\0';
	return (str);
}
