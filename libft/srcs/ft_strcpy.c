/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:09:20 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/08 06:32:19 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*orig_dest;

	orig_dest = dest;
	while (*src != '\0')
		*(dest++) = *(src++);
	*dest = '\0';
	return (orig_dest);
}
