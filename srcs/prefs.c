#include "ft_ls.h"
#include <sys/ioctl.h>
#include <unistd.h>

int		g_columns = 80;

void	ft_get_prefs(char *toptions)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	g_columns = w.ws_col;
	if (isatty(1))
		toptions[o_C] = 1;
	else
		toptions[o_1] = 1;
}
