/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:50:08 by eflorenz          #+#    #+#             */
/*   Updated: 2017/05/10 22:46:00 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <ctype.h>

char	*ft_char_to_oct(unsigned char c)
{
	char	*str;

	str = ft_strnew(3);
	str[2] = c % 8 + '0';
	str[1] = (c / 8) % 8 + '0';
	str[0] = (c / 64) % 8 + '0';
	str[3] = '\0';
	return (str);
}

int		ft_escape(unsigned char c)
{
	if (c == '\a' || c == '\b' || c == '\f' || c == '\n' || c == '\r' ||
			c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

char	ft_char_to_escape(unsigned char c)
{
	if (c == '\a')
		return ('a');
	if (c == '\b')
		return ('b');
	if (c == '\f')
		return ('f');
	if (c == '\n')
		return ('n');
	if (c == '\r')
		return ('r');
	if (c == '\t')
		return ('t');
	if (c == '\v')
		return ('v');
	return ('\\');
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

char	*ft_str_name_b(t_list *files)
{
	int		size;
	char	*ptr;
	char	*str;
	int		i;

	size = 0;
	ptr = ((t_file*)files->content)->dirent.d_name;
	while (*ptr != '\0')
	{
		if (isprint(*ptr))
			size++;
		else if (g_toptions[o_b] && ft_escape(*ptr))
			size += 2;
		else
			size += 4;
		ptr++;
	}
	str = ft_strnew(size + 1);
	ptr = ((t_file*)files->content)->dirent.d_name;
	i = 0;
	while (*ptr != '\0')
	{
		if (isprint(*ptr))
			str[i++] = *ptr;
		else if (g_toptions[o_b] && ft_escape(*ptr))
		{
			str[i] = '\\';
			str[i + 1] = ft_char_to_escape(*ptr);
			i += 2;
		}
		else
		{
			str[i] = '\\';
			str[i + 1] = '\0';
			ft_strcat(str, ft_char_to_oct(*ptr));
			i += 4;
		}
		ptr++;
	}
	str[i] = '\0';
	return (str);
}
