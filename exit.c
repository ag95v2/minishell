#include "environment.h"

void	builtin_exit(char **args, t_env env)
{
	(void)env;
	if (*args)
		exit(ft_atoi(args[0]));
	else
		exit(0);
}
