#include "environment.h"
#include "t_builtin.h"

extern char	**environ;

void	prompt(void)
{
	ft_putstr("minishell_v0.2_____$");
}

t_builtin	get_builtin(char *name)
{
	if (!ft_strcmp(name, "echo"))
		return (&builtin_echo);
	if (!ft_strcmp(name, "cd"))
		return (&builtin_cd);
	if (!ft_strcmp(name, "env"))
		return (&builtin_env);
	if (!ft_strcmp(name, "setenv"))
		return (&builtin_setenv);
	if (!ft_strcmp(name, "getenv"))
		return (&builtin_getenv);
	if (!ft_strcmp(name, "unsetenv"))
		return (&builtin_unsetenv);
	if (!ft_strcmp(name, "exit"))
		return (&builtin_exit);
	return (NULL);
}

int	main()
{
	char			*cmd;
	char			**words;
	unsigned int	nchar;
	t_builtin		builtin;
	t_env			env;

	if (!(env = init_env(environ)))
		return (1);
	prompt();
	while ((nchar = get_next_line(0, &cmd)))
	{
		if (!nchar)
		{
			prompt();
			continue ;
		}
		words = ft_strsplit(cmd, ' ');
		if (!words[0])
		{
			free(words);
			free(cmd);
			cmd = NULL;
			prompt();
			continue ;
		}
		if (!(builtin = get_builtin(words[0])))
		{
			ft_printf("Command not found: %s\n", words[0]);
			ft_printf("%s\n", "Path searching is still not implemented =)");
			del_array(words);
			free(cmd);
			cmd = NULL;
			prompt();
			continue ;
		}
		builtin(words + 1, env);
		del_array(words);
		free(cmd);
		cmd = NULL;
		prompt();
	}
	delenv(env);
	ft_putchar('\n');
	return (0);
}
