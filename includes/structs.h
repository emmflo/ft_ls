/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:51:09 by eflorenz          #+#    #+#             */
/*   Updated: 2018/01/02 08:58:00 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_file {
	char			*path;
	ssize_t			xattrs_buffsize;
	t_list			*xattrs;
	struct dirent	dirent;
	acl_t			acl;
	struct stat		stat;
}					t_file;

typedef struct		s_column_sizes {
	int				s;
	int				ino;
	int				nlink;
	int				size;
	int				user;
	int				group;
	int				flags;
}					t_column_sizes;

typedef struct		s_tab {
	void			**tab;
	int				tab_len;
	int				max;
}					t_tab;

typedef struct		s_xattr {
	char	*name;
	ssize_t	size;
	void	*attr;
}					t_xattr;

enum	options	{o_at, o_1, o_A, o_a, o_C, o_c, o_d, o_e, o_F, o_f, o_G, o_g,
				o_H, o_i, o_L, o_l, o_m, o_n, o_O, o_o, o_P, o_p, o_R, o_r,
				o_S, o_s, o_T, o_t, o_u, o_U, o_x};

extern char	*g_toptions;
extern char	g_colors_tab[][6];
extern char	*g_colors;
extern int	g_columns;
extern char	g_lscolors[22];
