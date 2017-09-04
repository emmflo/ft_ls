/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 22:46:00 by eflorenz          #+#    #+#             */
/*   Updated: 2017/09/04 22:46:01 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <errno.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/types.h>
# include "structs.h"
# include "display_utils.h"
# include "colors.h"
# include "columns.h"
# include "sizes.h"
# include "display_l.h"
# include "display_print.h"
# include "display_to_str.h"
# include "display_x.h"
# include "display_str_name.h"
# include "display_1.h"
# include "display_m.h"
# include "display_c_.h"
# include "display_date.h"
# include "get_color.h"
# include "get_total.h"
# include "display_permissions.h"
# include "ls_sort.h"
# include "ls_filter.h"
# include "ls_recursive.h"
# include "ls_utils.h"
# define NB_OPTIONS 30

t_list			*ft_merge(t_list *a, t_list *b, int cmp(void *, void *));
t_list			*ft_merge_sort(t_list *list, int cmp(void *, void *));
int				ft_lstlen(t_list *list);
void			lsopt(char *options);
void			opt_error(char option);
void			ft_ls(char *options, t_list *dirs);
void			ft_displayls(t_list *files);
char			*make_path(char *path, char *name);
int				ft_check_errno(char *pre);
void			ft_get_prefs(void);
void			ft_dir(char *path);
t_list			*ft_makefilelist(char *path, DIR *dir);
int				ft_nbrsize(int nb);
t_column_sizes	*ft_get_column_size(t_list *files);
void			get_xattr_names(t_file *file);
void			ft_display_xattrs(t_file *file);
void			ft_get_acls(t_file *file);
void			ft_display_acls(t_file *file);
char			*ft_str_name_b(t_list *files);
char			*ft_str_name_q(t_list *files);
t_list			*ft_makefilelist_d(t_list *dirs);
t_file			*ft_makefile(char *path, struct dirent *dirent);
void			ft_print_error(char *pre, char *error);
void			ft_print_errno(char *pre);
long long int	ft_get_total(t_list *files);
long long int	ft_get_size(t_file *file);
char			*ft_char_to_oct(unsigned char c);
int				ft_escape(unsigned char c);
char			ft_char_to_escape(unsigned char c);
void			ft_delattrs(void *content, size_t size);
void			*check_malloc(void *ptr);

#endif
