/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:14:04 by bgian             #+#    #+#             */
/*   Updated: 2020/02/02 21:31:23 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

int	builtin_exit(char **args, t_env env)
{
	char	*lst;

	(void)env;
	if (*args)
		exit(ft_atoi(args[0]));
	else if ((lst = ft_getenv(env, LAST_STATUS)))
		exit(ft_atoi(lst));
	else
		exit(0);
	return (1);
}
