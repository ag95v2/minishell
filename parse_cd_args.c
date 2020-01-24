/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cd_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:49:43 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 13:49:45 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -L flag is ignored
** -P flag is parsed
** Return pointer to first non-flag argument
*/

char	**parse_cd_args(char **args, int *flag_p)
{
	*flag_p = 0;
	while (*args)
	{
		if (!ft_strcmp(*args, "-L"))
		{
			args++;
			continue ;
		}
		else if (!ft_strcmp(*args, "-P"))
		{
			*flag_p = 1;
			args++;
			continue ;
		}
		else
			break ;
	}
	return (args);
}
