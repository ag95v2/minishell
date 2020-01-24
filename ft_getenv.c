/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:13:12 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 16:13:53 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

char			*ft_getenv(t_env env, char *name)
{
	t_ptree	*tree;

	tree = (t_ptree *)env;
	return (search_key(tree, name));
}
