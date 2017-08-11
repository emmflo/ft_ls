/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:21:54 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:31:50 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

void	ft_color_name_start(char *str, struct stat *buff_stat);
void	ft_color_name_end(char *str);
int		ft_color_index(char c);
char	*ft_make_color_str(int index);

#endif
