#include "ft_ls.h"

void	opt_error(char option)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putstr_fd("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 2);
	exit(1);
}

int		ft_check_errno(char *pre)
{
	if (errno != 0)
	{
		ft_putstr("ls: ");
		ft_putstr(pre);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		return (-1);
	}
	return (0);
}
