/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getelemarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:32:55 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/16 17:21:02 by emmflo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_getelemarray(void *tab, size_t n, size_t *dimensions,
		size_t *human_index)
{
	size_t	i;
	int		index;

	if (tab == NULL || dimensions == NULL || human_index == NULL)
		return (NULL);
	if (n == 0)
		return (tab);
	i = 1;
	index = human_index[0];
	while (i < n)
	{
		index = index * dimensions[i] + human_index[i];
		i++;
	}
	return (&tab[index]);
}
