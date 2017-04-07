/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:41:45 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/16 16:50:13 by emmflo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabiter(void **tab, size_t size, void (*f)(void*))
{
	size_t	i;

	if (tab == NULL || f == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		if (tab[i] == NULL)
			return ;
		(*f)(tab[i]);
		i++;
	}
}
