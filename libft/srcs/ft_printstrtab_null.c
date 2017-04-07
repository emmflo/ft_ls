/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinstrtab_null.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:51:01 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/16 03:45:27 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstrtab_null(char **tab)
{
	ft_tabiter_null((void**)tab, (void (*)(void*))&ft_putendl);
}
