/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 02:51:03 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/08 05:24:49 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*cur;

	next = *alst;
	while (next != NULL)
	{
		cur = next;
		next = cur->next;
		ft_lstdelone(&cur, del);
	}
	*alst = NULL;
}
