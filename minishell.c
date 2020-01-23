#include "environment.h"
#include "t_builtin.h"
#include "repl.h"
#include <signal.h>

extern char	**environ;

int			g_child;

/*
** Kill all children if they exist.
*/

void	handler(int s)
{
	(void)s;
	kill(g_child, SIGINT);
}

/*
** sa_flags  = 0 means that we do not restart blocking syscalls in case of
** SIGINT. (gnl will fail with EINTR and return -1) =)
*/

int	main()
{
	t_env				env;
	struct sigaction	signal_action;

	signal_action.sa_handler = handler;
	sigemptyset(&signal_action.sa_mask);
	signal_action.sa_flags = 0;
	sigaction(SIGINT, &signal_action, NULL);

	if (!(env = init_env(environ)))
	 	return (1);
	//signal(SIGINT, handler);
	repl(env);
	delenv(env);
	ft_putchar('\n');
	return (0);
}
