/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:08:30 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/08 22:16:39 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (src > dest)
	{
		while (i < n)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	else if (src < dest)
	{
		while (i < n)
		{
			((unsigned char*)dest)[n - i - 1] =
				((unsigned char*)src)[n - i - 1];
			i++;
		}
	}
	else
		return (dest);
	return (dest);
}
