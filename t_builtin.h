#ifndef T_BUILTIN_H
# define T_BUILTIN_H

# include "environment.h"

typedef	void	(*t_builtin)(char **args, t_env env);

void			builtin_echo(char **args, t_env env);
void			builtin_cd(char **args, t_env env);
void			builtin_getenv(char **args, t_env env);
void			builtin_setenv(char **args, t_env env);
void			builtin_unsetenv(char **args, t_env env);
void			builtin_env(char **args, t_env env);
void			builtin_exit(char **args, t_env env);

#endif
