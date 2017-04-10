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
# define NB_OPTIONS 22
//# define st_mtimespec st_mtim

t_list	*ft_merge(t_list *a, t_list *b, int cmp(void *, void *));
t_list	*ft_merge_sort(t_list *list, int cmp(void *, void *));
int		ft_lstlen(t_list *list);
char	*lsopt(char *options, char *toptions);
void	opt_error(char option);
void	ft_ls(char *options, t_list *dirs);
enum	e_options { o_l, o_R, o_a, o_r, o_t , o_A, o_x, o_C, o_1, o_S, o_F, o_f, o_g, o_p, o_m, o_o, o_c, o_u, o_U, o_T, o_n, o_i };
void	ft_displayls(t_list *files, char *toptions);
char	*make_path(char *path, char *name);
int		ft_check_errno(char *pre);
void	ft_get_prefs(char *toptions);
void	ft_dir(char *path, char *toptions);
t_list	*ft_makefilelist(char *path, DIR *dir);
int		ft_nbrsize(int nb);

typedef struct s_file {
	char			*path;
	struct dirent	dirent;
	struct stat		stat;
} t_file;

typedef struct		s_column_sizes
{
	int		nlink;
	int		size;
	int		user;
	int		group;
}					t_column_sizes;


#endif
