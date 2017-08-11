/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_l.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 00:43:14 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:22:27 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_L_H
# define DISPLAY_L_H

void	ft_display_l_file_first_part(t_list *file, t_column_sizes *cs,
		struct stat *buff_stat, t_file *file_content);
void	ft_display_l_file_second_part(t_column_sizes *cs,
		struct stat *buff_stat);
void	ft_display_l_file_third_part(t_list *file, t_column_sizes *cs,
		struct stat *buff_stat, t_file *file_content);
void	ft_display_l_file(t_list *file, t_column_sizes *cs);
void	ft_display_l(t_list *files, t_column_sizes *cs);

#endif
