/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 00:36:38 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 00:37:55 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZES_H
# define SIZES_H

int				ft_get_user_size(t_file *file);
int				ft_get_nlink_size(t_file *file);
int				ft_get_group_size(t_file *file);
int				ft_get_ino_size(t_file *file);
int				ft_get_size_size(t_file *file);
int				ft_get_flags_size(t_file *file);
int				ft_get_s_size(t_file *file);

#endif
