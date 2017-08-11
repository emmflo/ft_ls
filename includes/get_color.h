/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:31:28 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:31:45 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_COLOR_H
# define GET_COLOR_H

char	*ft_get_color_dir(struct stat *buff_stat);
char	*ft_get_color_reg_file(struct stat *buff_stat);
char	*ft_get_color(struct stat *buff_stat);

#endif
