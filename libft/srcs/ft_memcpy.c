/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:08:21 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/08 03:13:34 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;

	tmp_dest = (unsigned char*)dest;
	while (n > 0)
	{
		*(tmp_dest++) = *(unsigned char*)(src++);
		n--;
	}
	return ((unsigned char*)dest);
}
