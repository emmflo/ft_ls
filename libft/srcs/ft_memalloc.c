/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:07:43 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/15 07:42:05 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	i;

	if (size == 0)
		return (NULL);
	if (!(ptr = (char*)malloc(sizeof(char*) * size)))
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = 0;
	return ((void*)ptr);
}
