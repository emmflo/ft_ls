/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:10:08 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/08 18:52:36 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	long	max_search;

	if (little[0] == '\0')
		return ((char*)big);
	i = 0;
	max_search = len - ft_strlen(little) + 1;
	while (big[i] != '\0' && (long)i < max_search)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char*)&big[i]);
		i++;
	}
	return (NULL);
}
