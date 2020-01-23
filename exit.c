#include "environment.h"

extern int	g_last_command_status;

int	builtin_exit(char **args, t_env env)
{
	(void)env;
	if (*args)
		exit(ft_atoi(args[0]));
	else
		exit(g_last_command_status);
	return (1);
}
