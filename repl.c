#include "environment.h"
#include "t_builtin.h"
#include "find_exec.h"
#include "expansions.h"

static void	prompt(void)
{
	ft_putstr("minishell________$");
}

int	run_cmd(t_env env, char **words, char **cmd)
{
	int				status;
	t_builtin		builtin;

	if (!words[0])
		return (0);
	if (!(builtin = get_builtin(words[0])))
	{
		status = find_exec(words, env);
		ft_memdel((void **)cmd);
		return (status);
	}
	builtin(words + 1, env);
	return (0);
}

/*
** Read Eval Print Loop
*/

void	repl(t_env env)
{
	char			*cmd;
	char			**words;
	unsigned int	nchar;

	prompt();
	while ((nchar = get_next_line(0, &cmd)))
	{
		if (!expand_dollar(&cmd, env))
		{
			ft_memdel((void **)&cmd);
			continue ;
		}
		words = ft_strsplit(cmd, ' ');
		tilda_expansion(words, env);
		run_cmd(env, words, &cmd);
		del_array(words);
		ft_memdel((void **)&cmd);
		prompt();
	}
	return ;
}
