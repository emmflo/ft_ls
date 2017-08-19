/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_print.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 00:48:42 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/19 14:08:53 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_PRINT_H
# define DISPLAY_PRINT_H

void	ft_putino(t_list *files, t_column_sizes *cs);
void	ft_print_perm_and_type(t_file *file_content, struct stat *buff_stat);
void	ft_print_group_and_user(struct stat *buff_stat, t_column_sizes *cs);
int		ft_display_name(t_list *files, t_column_sizes *cs);

#endif
