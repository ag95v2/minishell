#include "environment.h"
#include "t_builtin.h"
#include "find_exec.h"
#include "expansions.h"
#include "unistd.h"
#include "limits.h"
#include "colors.h"

int	g_last_command_status;

static void	prompt(void)
{
	static char	hostname[HOST_NAME_MAX];
	static char	username[LOGIN_NAME_MAX];
	static char	wd[PATH_MAX];
	
	if (isatty(0))
	{
		if (gethostname(hostname, HOST_NAME_MAX) != -1 &&\
			getlogin_r(username, LOGIN_NAME_MAX) != -1)
		{
			ft_putstr(KGRN);
			ft_printf("%s@%s:", username, hostname);
		}
		if (getcwd(wd, PATH_MAX))
		{
			ft_putstr(KRED);
			ft_putstr(wd);
		}
		ft_putstr(KNRM);
		ft_putstr("$ ");
	}
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
	int				status_gnl;

	prompt();
	while ((status_gnl = get_next_line(0, &cmd)))
	{
		if (status_gnl == -1)
		{
			prompt();
			continue ;
		}
		if (!expand_dollar(&cmd, env))
		{
			ft_memdel((void **)&cmd);
			continue ;
		}
		words = ft_strsplit(cmd, ' ');
		tilda_expansion(words, env);
		g_last_command_status = run_cmd(env, words, &cmd);
		del_array(words);
		ft_memdel((void **)&cmd);
		prompt();
	}
	return ;
}
