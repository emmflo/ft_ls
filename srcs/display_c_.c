/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:23:16 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/15 06:12:39 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"

t_list	**ft_make_file_tab(t_list *files)
{
	t_list	**tab;
	int		len;
	int		i;

	len = ft_lstlen(files);
	if (!(tab = malloc(sizeof(t_list*) * len)))
		exit(1);
	i = 0;
	while (files != NULL)
	{
		tab[i] = files;
		i++;
		files = files->next;
	}
	return (tab);
}

int		ft_get_nb_lines_c_(int max, int tab_len)
{
	int		nb_columns;
	int		nb_lines;

	nb_columns = g_columns / max;
	nb_lines = tab_len / nb_columns + (tab_len % nb_columns != 0);
	return (nb_lines);
}

void	ft_print_c_(int j, t_tab *tab, int nb_lines,
		t_column_sizes *cs)
{
	char	*str;
	int		len;
	char	*name;

	while (j < tab->tab_len)
	{
		if (g_toptions[o_i])
			ft_putino(tab->tab[j], cs);
		str = ft_str_name(tab->tab[j], cs);
		name = ft_make_name(tab->tab[j]);
		len = ft_len_name(name, cs);
		ft_putstr(str);
		ft_strdel(&name);
		ft_strdel(&str);
		if (len % 8 != 0)
			ft_putchar('\t');
		if (j < tab->tab_len - 1)
			ft_putnchar('\t', (tab->max - len) / 8);
		j += nb_lines;
	}
}

void	ft_display_c_(t_list *files, t_column_sizes *cs)
{
	t_tab	tab;
	int		i;
	int		nb_lines;

	tab.tab = (void**)ft_make_file_tab(files);
	tab.tab_len = ft_lstlen(files);
	tab.max = ft_get_max_len(files, cs);
	tab.max = tab.max + (8 - tab.max % 8);
	nb_lines = ft_get_nb_lines_c_(tab.max, tab.tab_len);
	i = 0;
	while (i < nb_lines)
	{
		ft_print_c_(i, &tab, nb_lines, cs);
		i++;
		ft_putchar('\n');
	}
	free(tab.tab);
}