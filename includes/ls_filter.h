/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_filter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:09:02 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 03:10:40 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FILTER_H
# define LS_FILTER_H

int		ft_filter_dot(t_list *elem);
int		ft_filter_a_(t_list *elem);
int		ft_filter_errno(t_list *elem);
void	ft_filterlist(t_list **files);
void	ft_delfile(void *file, size_t size);

#endif
