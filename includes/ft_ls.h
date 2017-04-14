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
# define NB_OPTIONS 24
//# define st_mtimespec st_mtim

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
	t_list			*xattrs;
	acl_t			acl;
} t_file;

typedef struct		s_column_sizes
{
	int		nlink;
	int		size;
	int		user;
	int		group;
}					t_column_sizes;

enum			e_options { o_l, o_R, o_a, o_r, o_t , o_A, o_x, o_C, o_1, o_S,
   				o_F, o_f, o_g, o_p, o_m, o_o, o_c, o_u, o_U, o_T, o_n, o_i, o_at,
				o_e };
t_list			*ft_merge(t_list *a, t_list *b, int cmp(void *, void *));
t_list			*ft_merge_sort(t_list *list, int cmp(void *, void *));
int				ft_lstlen(t_list *list);
char			*lsopt(char *options, char *toptions);
void			opt_error(char option);
void			ft_ls(char *options, t_list *dirs);
void			ft_displayls(t_list *files, char *toptions);
char			*make_path(char *path, char *name);
int				ft_check_errno(char *pre);
void			ft_get_prefs(char *toptions);
void			ft_dir(char *path, char *toptions);
t_list			*ft_makefilelist(char *path, DIR *dir);
int				ft_nbrsize(int nb);
t_column_sizes	*ft_get_column_size(t_list *files, char *toptions);
void			get_xattr_names(t_file *file);
void			ft_display_xattrs(t_file *file);
void			ft_putnbr_fixed(int nb, int column_size, int right);
void			ft_get_acls(t_file *file);
void			ft_display_acls(t_file *file);

#endif
