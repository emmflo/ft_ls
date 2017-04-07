/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:45:17 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/17 13:48:20 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfilter(t_list *lst, int (*f)(t_list *elem))
{
	t_list	*prev;
	t_list	*next;
	t_list	*start;

	if (lst == NULL || f == NULL)
		return (lst);
	prev = NULL;
	next = NULL;
	start = NULL;
	while (lst != NULL)
	{
		if ((*f)(lst))
		{
			next = ft_lstnew(lst->content, lst->content_size);
			if (start == NULL)
				start = next;
			if (prev != NULL)
				prev->next = next;
			prev = next;
		}
		lst = lst->next;
	}
	return (start);
}
