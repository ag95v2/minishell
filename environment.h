/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:27:12 by bgian             #+#    #+#             */
/*   Updated: 2020/02/02 22:57:22 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <unistd.h>
# include "libft.h"

# define LAST_STATUS "__LST"

typedef t_ptree *t_env;

/*
** Convert between tree and char ** representations.
*/

int				split_env_entry(char *s, char **key, char **value);
t_env			init_env(char **environ);
char			**to_array(t_env env, int *memory_ok);
void			*del_array(char **arr);

void			delenv(t_env env);
t_env			copy_env(t_env env);

/*
** Value should be freeable. Return 0 in case of errors
*/

int				ft_setenv(t_env env, char *name, char *value);
void			ft_unsetenv(t_env env, char *name);
void			print_env(t_env env, int *memory_ok);

char			*ft_getenv(t_env env, char *name);

void			ft_putstr_echo(char *s);
char			*tabs_to_spaces(char *s);

#endif
