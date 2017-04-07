/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 00:15:22 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/08 22:14:17 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int nbr)
{
	int		size;

	size = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	int		neg;
	char	*str;

	neg = 0;
	if (n < 0)
	{
		if (n - 1 > 0)
			return (ft_strdup("-2147483648"));
		n = -n;
		neg = 1;
	}
	size = get_size(n) + neg;
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (neg)
		str[0] = '-';
	size--;
	while (size >= neg)
	{
		str[size--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
