#include "environment.h"
#include "t_builtin.h"
#include "repl.h"

extern char	**environ;

int	main()
{
	t_env			env;

	if (!(env = init_env(environ)))
		return (1);
	repl(env);
	delenv(env);
	ft_putchar('\n');
	return (0);
}
