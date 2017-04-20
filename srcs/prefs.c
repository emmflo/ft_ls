/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:27:37 by eflorenz          #+#    #+#             */
/*   Updated: 2017/04/20 11:53:08 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>
#include <unistd.h>

int		g_columns = 80;
char	*g_lscolors;
char	g_colors_tab[][6] = {
	"\x1b[30m", "\x1b[31m", "\x1b[32m", "\x1b[33m", "\x1b[34m",
	"\x1b[35m", "\x1b[36m", "\x1b[37m", "\x1b[39m",
	"\x1b[40m", "\x1b[41m", "\x1b[42m", "\x1b[43m", "\x1b[44m",
	"\x1b[45m", "\x1b[46m", "\x1b[47m", "\x1b[49m", ""};
char	*g_colors = "abcdefghxABCDEFGHX ";

void	ft_get_prefs(char *toptions)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	g_columns = w.ws_col;
	if (g_columns <= 0)
		g_columns = 80;
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
	g_lscolors = ft_strdup("exfxcxdxbxegedabagacad");
}
