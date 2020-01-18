#include <unistd.h>
#include "libft.h"

/*
** Print all arguments separated by ' '. Print \n.
** Implmented only -n flag which suppresses \n
*/

int	echo(int nargs, char **args)
{
	int	minus_n_flag;
	int	i;

	minus_n_flag = 0;
	i = 0;
	if (!nargs)
		return (0);
	if (!ft_strcmp(args[0], "-n"))
	{
		minus_n_flag = 1;
		i++;
	}
	while (i < nargs)
	{
		ft_putstr(args[i]);
		if (!minus_n_flag)
			ft_putchar(i == nargs ? '\n' : ' ');
		else if (i <= nargs)
			ft_putchar(' ');
		i++;
	}
	return (0);
}
