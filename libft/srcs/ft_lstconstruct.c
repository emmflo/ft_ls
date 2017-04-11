/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstconstruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:37:07 by eflorenz          #+#    #+#             */
/*   Updated: 2017/04/11 13:44:46 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstconstruct(t_list **first, t_list **last, t_list *new)
{
	if (first == NULL || last == NULL)
		return ;
	if (*first == NULL)
	{
		*first = new;
		*last = *first;
	}
	else
	{
		(*last)->next = new;
		*last = (*last)->next;
	}
}
