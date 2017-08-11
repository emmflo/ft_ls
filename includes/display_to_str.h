/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_to_str.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 00:54:14 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:11:50 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_TO_STR_H
# define DISPLAY_TO_STR_H

char	*ft_permission_to_str(t_file *file);
char	ft_type_to_char(struct stat *buff_stat);
char	*link_to_str(char *path, struct stat *buff_stat);
char	ft_f__char(struct stat *buff_stat);

#endif
