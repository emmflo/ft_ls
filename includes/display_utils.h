/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:05:02 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/15 04:54:03 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_UTILS_H
# define DISPLAY_UTILS_H

void	ft_putstr_fixed(char *str, int column_size, int right);
void	ft_putnbr_fixed(int nb, int column_size, int right);
int		ft_len_name(char *name, t_column_sizes *cs);
void	ft_putnchar(char c, int nb);
int		ft_get_max_len(t_list *files, t_column_sizes *cs);

#endif
