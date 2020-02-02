/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs_to_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:37:57 by bgian             #+#    #+#             */
/*   Updated: 2020/01/28 17:50:59 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*tabs_to_spaces(char *s)
{
	char	*start;

	if (!s)
		return (0);
	start = s;
	while (*s)
	{
		if (*s == '\t')
			*s = ' ';
		s++;
	}
	return (start);
}
