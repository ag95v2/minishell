#ifndef REPL_H
# define REPL_H

# include "environment.h"

void	repl(t_env env);
int		run_cmd(t_env env, char **words, char **cmd);

#endif
