/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:27:28 by eflorenz          #+#    #+#             */
/*   Updated: 2017/05/01 19:13:52 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

char	*g_toptions;

void	ft_override_opt(char opt)
{
	if (opt == '1' || opt == 'C' || opt == 'x' || opt == 'l' || opt == 'm')
	{
		g_toptions[o_1] = 0;
		g_toptions[o_C] = 0;
		g_toptions[o_x] = 0;
		g_toptions[o_l] = 0;
		g_toptions[o_m] = 0;
	}
	if (opt == 'f')
		g_toptions[o_a] = 1;
	if (opt == 'g' || opt == 'o')
		g_toptions[o_l] = 1;
	if (opt == 'c' || opt == 'u' || opt == 'U')
	{
		g_toptions[o_c] = 0;
		g_toptions[o_u] = 0;
		g_toptions[o_U] = 0;
	}
	if (opt == 'v' || opt == 'w' || opt == 'B' || opt == 'b' || opt == 'q')
	{
		g_toptions[o_v] = 0;
		g_toptions[o_w] = 0;
		g_toptions[o_B] = 0;
		g_toptions[o_b] = 0;
		g_toptions[o_q] = 0;
	}
	if (opt == 'n')
		g_toptions[o_l] = 1;
	if (opt == 'd')
		g_toptions[o_a] = 1;
	if (opt == 'p')
		g_toptions[o_F] = 0;
}

char	*lsopt(char *options)
{
	char	*pos;
	char	*valid_options;

	valid_options = ft_strdup("lRartAxC1SFfgpmocuUTni@ebBqvwGdLHPOs");
	while (*options != '\0')
	{
		if ((pos = ft_strchr(valid_options, *options)) != NULL)
		{
			ft_override_opt(*pos);
			g_toptions[pos - valid_options] = 1;
		}
		else
			opt_error(*options);
		options++;
	}
	ft_strdel(&valid_options);
	return (g_toptions);
}
