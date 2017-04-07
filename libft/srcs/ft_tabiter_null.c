/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabiter_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:42:43 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/16 17:05:37 by emmflo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabiter_null(void **tab, void (*f)(void*))
{
	if (tab == NULL || f == NULL)
		return ;
	while (*tab != NULL)
	{
		(*f)(*tab);
		tab++;
	}
}
