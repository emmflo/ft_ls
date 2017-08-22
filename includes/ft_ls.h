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
# include <stdio.h> //bite
# include <sys/acl.h>
# include <sys/types.h>
# define NB_OPTIONS 30
//# define st_mtimespec st_mtim

extern char	*g_toptions;
extern int	g_columns;
extern char	*g_colors;
extern char	g_colors_tab[][6];
extern char	g_lscolors[22];

typedef struct		s_xattr
{
	char	*name;
	void	*attr;
	ssize_t	size;
}					t_xattr;

typedef struct s_file {
	char			*path;
	struct dirent	dirent;
	struct stat		stat;
	int				xattrs_buffsize;
	t_list			*xattrs;
	acl_t			acl;
} t_file;

typedef struct		s_column_sizes
{
	int		nlink;
	int		size;
	int		user;
	int		group;
	int		flags;
	int		s;
	int		ino;
}					t_column_sizes;

typedef struct		s_tab
{
	void	**tab;
	int		tab_len;
	int		max;
}					t_tab;

/*enum			e_options { o_l, o_R, o_a, o_r, o_t , o_A, o_x, o_C, o_1, o_S,
   				o_F, o_f, o_g, o_p, o_m, o_o, o_c, o_u, o_U, o_T, o_n, o_i, o_at,
				o_e, o_b, o_B, o_q, o_v, o_w, o_G, o_d, o_L, o_H, o_P, o_O, o_s };*/
enum			e_options { o_at, o_1, o_A, o_a, o_C, o_c, o_d, o_e, o_F, o_f,
							o_G, o_g, o_H, o_i, o_L, o_l, o_m, o_n, o_O, o_o,
							o_P, o_p, o_R, o_r, o_S, o_s, o_T, o_t, o_u, o_U, o_x };
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
#endif
