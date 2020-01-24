/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:17:39 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 16:17:40 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Free NULL-terminated array of strings
*/

void	*del_array(char **env)
{
	char	**start;

	if (!*env)
	{
		free(env);
		return (NULL);
	}
	start = env;
	while (*env)
		free(*env++);
	free(start);
	return (NULL);
}
