/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:07:47 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/08 23:03:22 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;

	i = 0;
	while (i < (int)n && ((unsigned char*)s)[i] != (unsigned char)c)
		i++;
	if (i < (int)n && ((unsigned char*)s)[i] == (unsigned char)c)
		return (&((unsigned char*)s)[i]);
	else
		return (NULL);
}
