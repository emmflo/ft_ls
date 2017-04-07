/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:19:23 by eflorenz          #+#    #+#             */
/*   Updated: 2017/04/07 19:37:38 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char *argv[])
{
	int		i;
	t_list	*dirs;
	t_list	*ptr;
	t_list	*elem;
	char	options[100];
	char	*str;

	i = 1;
	options[0] = '\0';
	dirs = NULL;
	while (i < argc && argv[i][0] == '-')
	{
		if (argv[i][1] != '-')
			ft_strlcat(options, &argv[i++][1], 100);
		else
			i++;
	}
	while (i < argc)
	{
		str = ft_strdup(argv[i]);
		elem = ft_lstnew(argv[i], ft_strlen(argv[i]) + 1);
		if (dirs == NULL)
			dirs = elem;
		else
			ptr->next = elem;
		ptr = elem;
		i++;
	}
	ft_ls(options, dirs);
	return (0);
}
