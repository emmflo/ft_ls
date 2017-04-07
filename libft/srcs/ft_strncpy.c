/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:10:00 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/07 23:11:06 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*orig_dest;

	orig_dest = dest;
	while (*src != '\0' && n > 0)
	{
		*(dest++) = *(src++);
		n--;
	}
	while (n > 0)
	{
		*(dest++) = '\0';
		n--;
	}
	return (orig_dest);
}
