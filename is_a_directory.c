/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:10:13 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 16:10:17 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>

int		is_a_directory(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) == 0 && S_ISDIR(buf.st_mode))
		return (1);
	return (0);
}

/*
** Check if certain component of path is a directory
** (non-destructive, in-place)
*/

int		part_is_a_directory(char *start, char *end)
{
	char	c;
	int		ret;

	c = *end;
	*end = 0;
	ret = is_a_directory(start);
	*end = c;
	return (ret);
}
