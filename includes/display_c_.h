/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c_.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:23:56 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:37:31 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_C__H
# define DISPLAY_C__H

t_list	**ft_make_file_tab(t_list *files);
int		ft_get_nb_lines_c_(int max, int tab_len);
void	ft_print_c_(int j, t_tab *tab, int nb_lines,
		t_column_sizes *cs);
void	ft_display_c_(t_list *files, t_column_sizes *cs);

#endif
