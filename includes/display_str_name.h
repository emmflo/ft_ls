/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str_name.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 01:05:07 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/15 05:33:23 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_STR_NAME_H
# define DISPLAY_STR_NAME_H

char	*ft_str_name_(t_list *files);
char	*ft_str_name(t_list *files, t_column_sizes *cs);
char	*ft_str_name_q(t_list *files);
char	*ft_str_name_b(t_list *files);
int		ft_get_name_size_b(t_list *files);
char	*ft_make_name(t_list *files);

#endif
