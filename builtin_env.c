#include "repl.h"
#include "environment.h"

/*
** Process all cases like a=b c=d
** Return pointer to first argument not if format "name=value" (_COMMAND_)
** Return NULL in case of memory errors
*/

char			**update_copy(char **args, t_env copy)
{
	char	*key;
	char	*value;
	int		status;

	while (*args)
	{
		key = 0;
		value = 0;
		status = 0;
		status = split_env_entry(*args, &key, &value);
		if (status == 2)
			return (args);
		if (!status)
			return (NULL);
		if (status == 1 && !insert_value(copy, key, value))
			return (NULL);
		free(key);
		args++;
	}
	return (args);
}

/*
** Run _COMMAND_ in modified environment
** Example:
** env a=b c=d ./program
*/

int			builtin_env(char **args, t_env env)
{
	int		memory_ok;
	t_env	copy;

	if (!(copy = copy_env(env)))
	{
		ft_fprintf(2, "%s", "Not enough memory\n");
		return (0);
	}
	args = update_copy(args, copy);
	if (!args)
		return (0);
	if (!*args)
	{
		memory_ok = 1;
		print_env(copy, &memory_ok);
		if (!memory_ok)
			ft_fprintf(2, "%s", "Not enough memory\n");
	}
	else
		run_cmd(copy, args, NULL);
	delenv(copy);
	return (1);
}
