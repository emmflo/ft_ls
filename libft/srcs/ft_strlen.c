/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:09:46 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/19 17:29:53 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlen(const char *s)
{
	size_t  i;
	size_t  count;
	char    tmp;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] & 0x10000000) != 0)
		{
			tmp = s[i];
			count++;
			while ((tmp & 0x01000000) != 0)
			{
				i++;
				tmp <<= 1;
			}
		}
		else
			count++;
		i++;
	}
	return (count);
}
