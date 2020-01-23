#include "environment.h"
#include "unistd.h"
#include "find_path.h"
#include <sys/types.h>
#include <sys/wait.h>

extern int		g_child;

static char		**create_argv(char *progname, char **args)
{
	int		nargs;
	char	**new;

	nargs = 0;
	while (args[nargs++])
		;
	new = (char **)malloc(sizeof(char *) * (nargs + 1));
	if (!new)
		return (NULL);
	nargs++;
	while (--nargs)
		new[nargs] = args[nargs - 1];
	new[0] = progname;
	return (new);
}

static int	execute(char *progname, char **args, char **child_env)
{
	int		status;
	char	**argv;

	g_child = fork();
	if (g_child == -1)
	{
		ft_putendl_fd("Could not create child process", 2);
		return (-1);
	}
	if (!g_child)
	{
		argv = create_argv(progname, args);
		execve(progname, argv, child_env);
		ft_putendl_fd("Execution error", 2);
		exit (-1);
	}
	else
	{
		waitpid(g_child, &status, 0);
		g_child = 0;
		return (WEXITSTATUS(status));
	}
}

static int	no_exec_rights(char *progname)
{
	ft_fprintf(2, "minishell: %s: Permission denied\n", progname);
	free(progname);
	return (-1);
}

static int	memory_trouble(char **child_env)
{
	del_array(child_env);
	ft_putendl_fd("Could not allocate memory for new process", 2);
	return (-1);
}

int			find_exec(char **args, t_env env)
{
	char	**child_env;
	char	*progname;
	int		status;
	int		memory_ok;

	if (!*args)
		return (-1);
	progname = find_path(args[0], env);
	if (!progname)
	{
		ft_fprintf(2, "%s: command not foud\n", args[0]);
		return (-1);
	}
	if (access(progname, X_OK) != 0)
		return (no_exec_rights(progname));
	child_env = to_array(env, &memory_ok);
	if (!memory_ok)
		return (memory_trouble(child_env));
	status = execute(progname, args + 1, child_env);
	free(progname);
	del_array(child_env);
	return (status);
}
