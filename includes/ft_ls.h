#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <errno.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# define NB_OPTIONS 7
# define st_mtimespec st_mtim

t_list	*ft_merge(t_list *a, t_list *b, int cmp(void *, void *));
t_list	*ft_merge_sort(t_list *list, int cmp(void *, void *));
char	*lsopt(char *options);
void	opt_error(char option);
void	ft_ls(char *options, t_list *dirs);
enum	e_options { o_l, o_R, o_a, o_r, o_t , o_A, not_first};
typedef struct s_file {
	char			*path;
	struct dirent	dirent;
	struct stat		stat;
} t_file;

#endif
