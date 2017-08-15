/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:09:27 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/15 07:40:06 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;

	if (!(d = (char*)malloc(sizeof(char*) * (ft_strlen(s) + 1))))
		return (NULL);
	ft_strcpy(d, s);
	return (d);
}
