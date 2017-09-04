/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:19:23 by eflorenz          #+#    #+#             */
/*   Updated: 2017/09/04 18:33:59 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_realloc(char *str, int size)
{
	char	*new;

	check_malloc(new = ft_strnew(size));
	ft_strcpy(new, str);
	free(str);
	return (new);
}

char	*get_options(int argc, char *argv[], int *i)
{
	char	*options;
	int		buff_size;

	buff_size = 100;
	check_malloc(options = ft_strnew(buff_size));
	options[0] = '\0';
	while (*i < argc && argv[*i][0] == '-')
	{
		if (argv[*i][1] != '-')
			ft_strlcat(options, &argv[(*i)++][1], 100);
		else
			(*i)++;
		if (*i > buff_size)
		{
			buff_size *= 2;
			options = ft_realloc(options, buff_size);
		}
	}
	return (options);
}

int		main(int argc, char *argv[])
{
	int		i;
	t_list	*dirs;
	t_list	*ptr;
	char	*options;
	char	*str;

	i = 1;
	dirs = NULL;
	options = get_options(argc, argv, &i);
	while (i < argc)
	{
		str = ft_strdup(argv[i]);
		ft_lstconstruct(&dirs, &ptr,
			check_malloc(ft_lstnew(str, ft_strlen(str) + 1)));
		ft_strdel(&str);
		i++;
	}
	ft_ls(options, dirs);
	return (0);
}
