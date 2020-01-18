#include "libft.h"

/*
** Free NULL-terminated array of strings
*/

void	*del_array(char **env)
{
	char	**start;

	start = env;
	while (*env)
		free(*env++);
	free(start);
	return (NULL);
}
