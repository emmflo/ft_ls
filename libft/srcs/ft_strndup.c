/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:51:37 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/16 01:07:22 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*d;
	size_t	size;
	size_t	len_s;

	len_s = ft_strlen(s);
	size = len_s < n ? len_s : n;
	if (!(d = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strncpy(d, s, n);
	return (d);
}
