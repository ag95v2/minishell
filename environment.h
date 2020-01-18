#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <unistd.h>
# include "libft.h"

typedef t_ptree *t_env;

/*
** Convert between tree and char ** representations.
*/

t_env			init_env(char **environ);
char			**to_array(t_env env, int *memory_ok);
void			*del_array(char **arr);

void			delenv(t_env env);
t_env			copy_env(t_env env);
void			*setenv(t_env env, char *name, char *value);
void			unsetenv(t_env env, char *name);
void			print_env(t_env env, int *memory_ok);

#endif
