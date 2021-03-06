/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:19:23 by bgian             #+#    #+#             */
/*   Updated: 2020/02/02 20:54:48 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

void			delenv(t_env env)
{
	del_tree((t_ptree *)env);
}

t_env			copy_env(t_env env)
{
	return ((t_env)copy_ptree((t_ptree *)env));
}

/*
** Name should be freed later by caller
** Value should be freeable
*/

int				ft_setenv(t_env env, char *name, char *value)
{
	return (insert_value((t_ptree *)env, name, value));
}

void			ft_unsetenv(t_env env, char *name)
{
	del_key((t_ptree *)env, name);
}

void			print_env(t_env env, int *memory_ok)
{
	char	**arr;
	char	**start;

	arr = to_array(env, memory_ok);
	if (!(*memory_ok))
		return ;
	start = arr;
	while (*arr)
	{
		ft_printf("%s\n", *arr);
		arr++;
	}
	del_array(start);
}
