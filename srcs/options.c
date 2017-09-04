/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:27:28 by eflorenz          #+#    #+#             */
/*   Updated: 2017/09/04 20:41:43 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

char	*g_toptions;

void	ft_override_opt_1_cxlm(char opt)
{
	if (opt == '1' || opt == 'C' || opt == 'x' || opt == 'l' || opt == 'm')
	{
		g_toptions[o_1] = 0;
		g_toptions[o_C] = 0;
		g_toptions[o_x] = 0;
		g_toptions[o_l] = 0;
	}
}

void	ft_override_opt_cu_u(char opt)
{
	if (opt == 'c' || opt == 'u' || opt == 'U')
	{
		g_toptions[o_c] = 0;
		g_toptions[o_u] = 0;
		g_toptions[o_U] = 0;
	}
}

void	ft_override_opt(char opt)
{
	ft_override_opt_1_cxlm(opt);
	if (opt == 'f')
		g_toptions[o_a] = 1;
	if (opt == 'g' || opt == 'o')
		g_toptions[o_l] = 1;
	ft_override_opt_cu_u(opt);
	if (opt == 'n')
		g_toptions[o_l] = 1;
	if (opt == 'd')
		g_toptions[o_a] = 1;
	if (opt == 'p')
		g_toptions[o_F] = 0;
	if (opt == 'H' || opt == 'P')
		g_toptions[o_L] = 0;
}

void	ft_cancel_opt(char opt)
{
	if (opt == 'G' && !isatty(1))
		g_toptions[o_G] = 0;
	if (opt == 'C' && g_toptions[o_m])
		g_toptions[o_C] = 0;
}

void	lsopt(char *options)
{
	char	*pos;
	char	*valid_options;

	valid_options = ft_strdup("@1AaCcdeFfGgHiLlmnOoPpRrSsTtuUx");
	while (*options != '\0')
	{
		if ((pos = ft_strchr(valid_options, *options)) != NULL)
		{
			ft_override_opt(*pos);
			g_toptions[pos - valid_options] = 1;
			ft_cancel_opt(*pos);
		}
		else
			opt_error(*options);
		options++;
	}
	ft_strdel(&valid_options);
}
