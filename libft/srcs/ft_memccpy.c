/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:07:45 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/08 23:24:21 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*c_pos;

	c_pos = ft_memchr(src, c, n);
	if (c_pos != NULL)
	{
		ft_memcpy(dest, src, c_pos - src + 1);
		return (&dest[c_pos - src + 1]);
	}
	else
	{
		ft_memcpy(dest, src, n);
		return (NULL);
	}
}
