/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:43:07 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 13:43:46 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "t_builtin.h"
#include "repl.h"
#include <signal.h>

int			g_child;

/*
** Kill (only) child if it exists.
*/

void		handler(int s)
{
	(void)s;
	kill(g_child, SIGINT);
}

/*
** sa_flags  = 0 means that we do not restart blocking syscalls in case of
** SIGINT. (gnl will fail with EINTR and return -1) =)
** third parameter in main() is used  instead of extern char	**environ;
*/

int			main(int argc, char **argv, char **environ)
{
	t_env				env;
	struct sigaction	signal_action;

	(void)argc;
	(void)argv;
	signal_action.sa_handler = handler;
	sigemptyset(&signal_action.sa_mask);
	signal_action.sa_flags = 0;
	sigaction(SIGINT, &signal_action, NULL);

	if (!(env = init_env(environ)))
	 	return (1);
	repl(env);
	delenv(env);
	ft_putchar('\n');
	return (0);
}
