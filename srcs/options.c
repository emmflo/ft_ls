#include "ft_ls.h"
#include <stdio.h>

char	*lsopt(char *options)
{
	char	*pos;
	int		i;
	char	*toptions;
	char	*valid_options;

	toptions = ft_strnew(NB_OPTIONS);
	valid_options = ft_strdup("lRartAxC ");
	i = 0;
	while (i < NB_OPTIONS)
		toptions[i++] = 0;
	while (*options != '\0')
	{
		if ((pos = ft_strchr(valid_options, *options)) != NULL)
			toptions[pos - valid_options] = 1;
		else
			opt_error(*options);
		options++;
	}
	return (toptions);
}
