/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:09:44 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/08 23:00:52 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	ret;
	int		i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len > size)
		ret = size + src_len;
	else
		ret = dest_len + src_len;
	while (*dest != '\0')
		dest++;
	i = 0;
	while (*(src) != '\0' && i < (int)(size - dest_len - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ret);
}
