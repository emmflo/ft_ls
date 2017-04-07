#include "ft_ls.h"

void	opt_error(char option)
{
	ft_putstr("ls : option invalide -- '");
	ft_putchar(option);
	ft_putstr("'\nSaisissez « ls --help » pour plus d'informations.\n");
	exit(2);
}
