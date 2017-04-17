/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:27:37 by eflorenz          #+#    #+#             */
/*   Updated: 2017/04/17 17:03:09 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>
#include <unistd.h>

int		g_columns = 80;

void	ft_get_prefs(char *toptions)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	g_columns = w.ws_col;
	if (isatty(1))
	{
		toptions[o_q] = 1;
		toptions[o_C] = 1;
	}
	else
	{
		toptions[o_1] = 1;
		toptions[o_v] = 1;
		toptions[o_w] = 1;
	}
}
