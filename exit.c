/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:14:04 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 16:14:06 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

extern int	g_last_command_status;

int	builtin_exit(char **args, t_env env)
{
	(void)env;
	if (*args)
		exit(ft_atoi(args[0]));
	else
		exit(g_last_command_status);
	return (1);
}
