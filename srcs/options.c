#include "ft_ls.h"
#include <stdio.h>

void	ft_override_opt(char opt, char *toptions)
{
	if (opt == '1' || opt == 'C' || opt == 'x' || opt == 'l' || opt == 'm')
	{
		toptions[o_1] = 0;
		toptions[o_C] = 0;
		toptions[o_x] = 0;
		toptions[o_l] = 0;
		toptions[o_m] = 0;
	}
	if (opt == 'f')
		toptions[o_a] = 1;
	if (opt == 'g' || opt == 'o')
		toptions[o_l] = 1;
	if (opt == 'c' || opt == 'u' || opt == 'U')
	{
		toptions[o_c] = 0;
		toptions[o_u] = 0;
		toptions[o_U] = 0;
	}
}

char	*lsopt(char *options, char *toptions)
{
	char	*pos;
	char	*valid_options;

	valid_options = ft_strdup("lRartAxC1SFfgpmocuUTn");
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
