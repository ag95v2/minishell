/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:43:07 by bgian             #+#    #+#             */
/*   Updated: 2020/02/02 21:30:29 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "t_builtin.h"
#include "repl.h"
#include <signal.h>

pid_t			g_child;

void		handler(int s)
{
	(void)s;
	write(0, "\n", 1);
	if (!g_child)
		prompt();
}

/*
** sa_flags  = 0 means that we do not restart blocking syscalls in case of
** SIGINT. (gnl will fail with EINTR and return -1) =)
** third parameter in main() is used  instead of extern char	**environ;
*/

int			main(int argc, char **argv, char **environ)
{
	t_env				env;
	char				*c;

	(void)argc;
	(void)argv;
	signal(SIGINT, &handler);
	if (!(env = init_env(environ)))
		return (1);
	ft_unsetenv(env, "OLDPWD");
	if (!(c = ft_strdup("0")) || !ft_setenv(env, LAST_STATUS, c))
	{
		free(c);
		ft_putendl_fd("Could not set last cmd status. Not a big problem", 2);
	}
	repl(env);
	delenv(env);
	ft_putchar('\n');
	return (0);
}
