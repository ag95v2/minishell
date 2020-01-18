#include "libft.h"

void	exit(int nargs, char **args, int last_status)
{
	if (nargs > 0)
		exit(ft_atoi(args[0]));
	else
		exit(last_status);
}
