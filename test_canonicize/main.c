#include "cd_utils.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	char	*c;

	if (argc == 1)
	{
		ft_printf("%s\n", "Usage: ./canonicize path");
		return (0);
	}
	
	c = ft_strdup(argv[1]);
	if (!c || !canonicize(c, 1))
		return (ft_printf("%s\n", "error"));
	ft_printf("%s\n", c);
	return (0);
}
