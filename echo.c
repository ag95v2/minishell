/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:17:51 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 16:17:52 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "environment.h"

/*
** Print all arguments separated by ' '. Print \n.
** Implmented only -n flag which suppresses \n
*/

int	builtin_echo(char **args, t_env env)
{
	int	minus_n_flag;
	int	i;

	(void)env;
	minus_n_flag = 0;
	i = 0;
	if (!*args)
		return (1);
	if (!ft_strcmp(args[0], "-n"))
	{
		minus_n_flag = 1;
		i++;
	}
	while (*args)
	{
		ft_putstr(*args);
		if (!minus_n_flag)
			ft_putchar(!*(args + 1) ? '\n' : ' ');
		else if (*(args + 1))
			ft_putchar(' ');
		args++;
	}
	return (1);
}
