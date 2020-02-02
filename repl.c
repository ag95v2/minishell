/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:45:27 by bgian             #+#    #+#             */
/*   Updated: 2020/02/02 21:30:51 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "t_builtin.h"
#include "find_exec.h"
#include "expansions.h"
#include "unistd.h"
#include "limits.h"
#include "colors.h"
#include "name_max.h"

void		prompt(void)
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

/*
**	All bulilltins return 0 according to convention
*/

int			run_cmd(t_env env, char **words, char **cmd)
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

void		update_status(t_env env, int status)
{
	char	*lst_cmd;

	lst_cmd = ft_itoa(status);
	if (!lst_cmd)
	{
		ft_putendl_fd("Could not set last cmd status.", 2);
		return ;
	}
	if (!ft_setenv(env, LAST_STATUS, lst_cmd))
	{
		ft_memdel((void **)&lst_cmd);
		ft_putendl_fd("Could not set last cmd status. Not a big problem", 2);
	}
}

/*
** Read Eval Print Loop
*/

void		repl(t_env env)
{
	char			*cmd;
	char			**words;
	int				status_gnl;
	int				lst_cmd_status;

	prompt();
	while ((status_gnl = get_next_line(0, &cmd)))
	{
		if (!expand_dollar(&cmd, env))
		{
			ft_memdel((void **)&cmd);
			continue ;
		}
		words = ft_strsplit(tabs_to_spaces(cmd), ' ');
		tilda_expansion(words, env);
		lst_cmd_status = run_cmd(env, words, &cmd);
		update_status(env, lst_cmd_status);
		del_array(words);
		ft_memdel((void **)&cmd);
		prompt();
	}
	return ;
}
