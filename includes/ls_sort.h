/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:26:10 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 03:27:00 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_SORT_H
# define LS_SORT_H

int		ft_st_sizecmp(void *a, void *b);
int		ft_st_sizecmp_r(void *a, void *b);

int		ft_d_namecmp(void *a, void *b);
int		ft_d_namecmp_r(void *a, void *b);

int		ft_st_btimcmp(void *a, void *b);
int		ft_st_btimcmp_r(void *a, void *b);
t_list	*ft_sortfiles_bytime_b(t_list *files);

int		ft_st_ctimcmp(void *a, void *b);
int		ft_st_ctimcmp_r(void *a, void *b);
t_list	*ft_sortfiles_bytime_c(t_list *files);

int		ft_st_atimcmp(void *a, void *b);
int		ft_st_atimcmp_r(void *a, void *b);
t_list	*ft_sortfiles_bytime_u(t_list *files);

int		ft_st_mtimcmp(void *a, void *b);
int		ft_st_mtimcmp_r(void *a, void *b);
t_list	*ft_sortfiles_bytime_m(t_list *files);

int		ft_st_timcmp(struct timespec *a, struct timespec *b);
t_list	*ft_sortfiles_bytime(t_list *files);

t_list	*ft_sortfiles(t_list *files);

#endif
