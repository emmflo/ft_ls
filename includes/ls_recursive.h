/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:17:16 by eflorenz          #+#    #+#             */
/*   Updated: 2017/08/11 03:18:24 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_RECURSIVE_H
# define LS_RECURSIVE_H

void	ft_delino(void *ino, size_t size);
int		ft_inoinlst(t_list *visited, ino_t ino);
void	ft_print_header(t_file *content, char *name);
void	ft_manage_ptr_start(char *path, t_list *visited, t_list *ptr,
		t_list *prev);
void	ft_recursive(t_list *files, char *path);

#endif
