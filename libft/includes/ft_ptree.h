/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:07:50 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 17:12:07 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PTREE_H
# define FT_PTREE_H

# define N_CHILDREN 256

# include "libft.h"

/*
** Prefix tree data structure
** key - value pairs, keys are strings, values - *void
** value must be freeable (TODO: arbitrary)
**
** NULL value means lack of value
** If no children and no value, we can delete a node and check parent
** (not really needed)
*/

typedef struct		s_ptree
{
	struct s_ptree	*child[N_CHILDREN];
	void			*value;
}					t_ptree;

t_ptree				*new_tree(void);

/*
** Return value of key if it exists
*/

void				*search_key(t_ptree *tree, char *key);

/*
** Return nonzero on success
** Remove old entry properly if needed
** If NULL is provided instead of tree, create a new tree
*/

int					insert_value(t_ptree *tree, char *key, void *value);
void				del_key(t_ptree *tree, char *key);
void				del_tree(t_ptree *tree);

/*
** Copy tree with all contents.
** Modification of copy never affects original tree
*/

t_ptree				*copy_ptree(t_ptree *tree);

typedef	struct		s_key_value
{
	char			*key;
	void			*value;
}					t_key_value;

/*
** Convert ptree to list of  key-value pairs
**
** If no values are present on the tree and some keys (yes, this is possible),
** return single node of list with empty content.
**
** Return 0 in case of malloc errors.
*/

t_list				*ptree_to_kvpairs(t_ptree *tree);

#endif
