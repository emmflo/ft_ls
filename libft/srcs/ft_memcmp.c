/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:08:12 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/08 16:54:42 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*(unsigned char*)s1 == *(unsigned char*)s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
