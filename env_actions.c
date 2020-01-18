#include "environment.h"

void			delenv(t_env env)
{
	del_tree((t_ptree *)env);
}

t_env			copy_env(t_env env)
{
	return ((t_env)copy_ptree((t_ptree *) env));
}

int				setenv(t_env env, char *name, char *value)
{
	(t_ptree *)env;
	return (insert_value(env, name, value));
	
}

void			unsetenv(t_env env, char *name)
{
	(t_ptree *)env;
	del_key(env, name);
}

void			print_env(t_env env, int *memory_ok)
{
	char	**arr;
	char	**start;

	arr = to_array(env, memory_ok);
	if (!(*memory_ok))
		return ;
	start = arr;
	while (*arr)
	{
		ft_printf("%s\n", *arr);
		arr++;
	}
	del_array(start);
}
