#include "ft_ls.h"
#include <stdio.h>

void	ft_override_opt(char opt, char *toptions)
{
	if (opt == '1' || opt == 'C' || opt == 'x' || opt == 'l')
	{
		toptions[o_1] = 0;
		toptions[o_C] = 0;
		toptions[o_x] = 0;
		toptions[o_l] = 0;
	}
}

char	*lsopt(char *options, char *toptions)
{
	char	*pos;
	char	*valid_options;

	valid_options = ft_strdup("lRartAxC1S ");
	while (*options != '\0')
	{
		if ((pos = ft_strchr(valid_options, *options)) != NULL)
		{
			ft_override_opt(*pos, toptions);
			toptions[pos - valid_options] = 1;
		}
		else
			opt_error(*options);
		options++;
	}
	return (toptions);
}
