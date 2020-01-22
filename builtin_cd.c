#include "libft.h"
#include "environment.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "cd_utils.h"

void	change_wd(char *where, int flag_p, t_env env)
{
	char	*oldpwd;
	char	*pwd;
	char	wd[PATH_MAX];

	if (!ft_strcmp(where, "-"))
	{
		if (!(oldpwd = ft_getenv(env, "OLDPWD")))
		{
			ft_fprintf(2, "%s", "cd: OLDPWD is unset\n");
			return ;
		}
		if (chdir(oldpwd) == -1)
		{
			ft_fprintf(2, "cd: Cannot change directory to %s\n", oldpwd);
			return ;
		}
	}
	if (chdir(where) == -1)
	{
		ft_fprintf(2, "cd: Cannot change directory to %s\n", where);
		return ;
	}
	pwd = ft_getenv(env, "PWD");
	if (!pwd && !(getcwd(wd, PATH_MAX)))
		return ;
	ft_setenv(env, "OLDPWD", ft_strdup(pwd));
	ft_setenv(env, "PWD", flag_p ? ft_strdup(wd) : where);
}

/*
** https://pubs.opengroup.org/onlinepubs/9699919799/
**
** If PWD is unset, the behavior of cd is unspecified by POSIX.
** We prefer to getcwd() in this case
*/

void	builtin_cd(char **args, t_env env)
{
	int			flag_p;
	char		*curpath;
	static char	pwd[PATH_MAX];
	char		*canonic_path;

	args = parse_cd_args(args, &flag_p);
	if (!(curpath = get_curpath(args)))
		return ;
	if (flag_p)
		change_wd(curpath, env);
	if (*curpath != '/')
	{
		if (!(pwd = ft_getenv(env, "PWD")) && !getcwd(pwd, PATH_MAX))
		{	
			ft_putstr_fd(ERR_UNSET_PWD, 2);
			return ;
		}
		if (!(canonic_path = ft_path_append(pwd, curpath)))
			return ;
		ft_memdel((void **)&curpath);
	}
	if (!canonicize(canonic_path))
		return ;
	change_wd(canonic_path, env);
}
