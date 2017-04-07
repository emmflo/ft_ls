/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:09:54 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/07 23:09:55 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *orig_dest;

	orig_dest = dest;
	while (*dest != '\0')
		dest++;
	while (*(src) != '\0' && n-- > 0)
		*(dest++) = *(src++);
	*dest = '\0';
	return (orig_dest);
}
