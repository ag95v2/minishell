#include "environment.h"

void			builtin_getenv(char **args, t_env env)
{
	char	*c;

	if (!args[0])
	{
		ft_printf("%s", "Usage: getenv name\n");
		return ;
	}
	while (*args)
	{
		c = ft_getenv(env, args[0]);
		if (!c)
			ft_printf("No such variable in env: %s\n", args[0]);
		else
			ft_printf("%s=%s\n", args[0], c);
		args++;
	}
}

/*
** According to POSIX, names shall not contain '='
** https://pubs.opengroup.org/onlinepubs/000095399/basedefs/xbd_chap08.html
** Bash also does not tolerate ':', but we do
*/

void			builtin_setenv(char **args, t_env env)
{
	char	*tmp;

	if (!*args)
		return ;
	if (*args && !*(args+1))
	{
		ft_setenv(env, *args, ft_strdup(""));
		return ;
	}
	tmp = *args;
	while (*tmp)
	{
		if (*tmp == '=')
			return ;
		tmp++;
	}
	if (!ft_setenv(env, *args, ft_strdup(*(args + 1))))
		ft_printf("Error: Could not set env\n");
}

void			builtin_unsetenv(char **args, t_env env)
{
	while (*args)
	{
		ft_unsetenv(env, *args);
		args++;
	}
}

void			builtin_env(char **args, t_env env)
{
	int	memory_ok;

	if (!*args)
	{
		memory_ok = 1;
		print_env(env, &memory_ok);
		if (!memory_ok)
			ft_printf("Not enough memory\n");
	}
	else
	{
		ft_printf("This case is not implemented yet.\n");
	}
}
