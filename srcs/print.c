/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:50:08 by eflorenz          #+#    #+#             */
/*   Updated: 2017/09/04 18:32:52 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <ctype.h>

char	*ft_char_to_oct(unsigned char c)
{
	char	*str;

	check_malloc(str = ft_strnew(3));
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
