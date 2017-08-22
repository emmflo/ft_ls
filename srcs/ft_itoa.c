/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:00:33 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/10 23:01:26 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrsize(int nb)
{
	int	i;
	int	neg;

	neg = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
	}
	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i + neg);
}

char	*ft_itoa(int nb)
{
	int		len;
	char	*str;
	int		i;
	int		neg;

	len = ft_nbrsize(nb);
	check_malloc(str = ft_strnew(len));
	neg = 0;
	if (nb == 0)
		return (ft_strcpy(str, "0"));
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
		str[0] = '-';
	}
	i = len - neg - 1;
	while (i >= 0)
	{
		str[neg + i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (str);
}
