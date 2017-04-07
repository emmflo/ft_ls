/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinplacefilter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:45:07 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/15 18:45:09 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinplacefilter(t_list **lst, int (*f)(t_list *elem),
		void (*del)(void *, size_t))
{
	t_list	*prev;
	t_list	*elem;
	t_list	*next;

	if (lst == NULL || f == NULL || del == NULL)
		return ;
	prev = NULL;
	elem = *lst;
	next = NULL;
	while (elem != NULL)
	{
		next = elem->next;
		if (!(*f)(elem))
		{
			if (prev == NULL)
				*lst = next;
			else
				prev->next = next;
			ft_lstdelone(&elem, del);
		}
		else
			prev = elem;
		elem = next;
	}
}
