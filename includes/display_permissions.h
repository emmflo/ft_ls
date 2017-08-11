/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_permissions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:43:55 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 01:45:51 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_PERMISSIONS_H
# define DISPLAY_PERMISSIONS_H

char	*ft_init_permission_str(void);
char	*ft_permission_to_str(t_file *file);
void	ft_permission_user(char *permissions, struct stat *buff_stat);
void	ft_permission_group(char *permissions, struct stat *buff_stat);
void	ft_permission_other(char *permissions, struct stat *buff_stat);
void	ft_permission_extra(char *permissions, t_file *file);

#endif
