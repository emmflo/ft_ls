#include "ft_ls.h"
#include <sys/ioctl.h>

int		g_columns = 80;

void	ft_get_prefs(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	g_columns = w.ws_col;
}
