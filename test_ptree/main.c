#include "libft.h"
#include <stdio.h>

#define LEN 7

void		print_key_if_exists(t_ptree *tree, char *key)
{
	char	*s;

	if (!key)
		return ;
	if (!(s = (char *)search_key(tree, key)))
		printf("Key not found: %s\n", key);
	else
		printf("%s = %s\n", key, (char *)search_key(tree, key));
}

void		insert_duplicate(t_ptree *tree, char *key, char *value)
{
	insert_value(tree, key, ft_strdup(value));
}

void		fill_tree(t_ptree *tree, char *keys[], char *values[])
{
	int	i;

	i = 0;

	while (i < LEN)
	{
		insert_duplicate(tree, keys[i], values[i]);
		i++;
	}
}

void		print_keys(t_ptree *tree, char *keys[])
{
	int	i;

	i = 0;

	while (i < LEN)
	{
		print_key_if_exists(tree, keys[i]);
		i++;
	}
}

void		remove_key(t_ptree *tree, char *key)
{
	printf("%s: %s\n", "Removing key", key);
	del_key(tree, key);
}


void					del_kvpair1(t_key_value **kv)
{
	ft_memdel((void **)&((*kv)->key));
	ft_memdel((void **)&((*kv)->value));
	ft_memdel((void **)kv);
}

void		del_kventry(void *data, size_t size)
{
	(void)size;
	if (!data)
		return ;
	del_kvpair1((t_key_value **)&data);
}

void		print_kventry(t_list *elem)
{
	if (!elem->content)
		return ;
	printf("%s: %s\n", (char *)((t_key_value *)elem->content)->key, 
					   (char *)((t_key_value *)elem->content)->value);
}

int	main()
{
	t_ptree	*tree;
	t_ptree	*copy;
	char	*keys[]   =     {"a",   "aa",  "ab",  "abc",  "ac", "aca", "abcc"};
	char	*values[] =     {"Va", "Vaa", "Vab", "Vabc", "Vac", "Vaca", "Vabcc"};
	t_list	*kvpairs;

	tree = new_tree();
	fill_tree(tree, keys, values);
	print_keys(tree, keys);
	remove_key(tree, keys[1]);
	print_key_if_exists(tree, keys[1]);
	insert_duplicate(tree, keys[1], "New value");
	print_key_if_exists(tree, keys[1]);

	copy = copy_ptree(tree);
	insert_duplicate(copy, keys[1], "New value(modified copy)");
	insert_duplicate(tree, keys[1], "New value(modified original)");
	printf("%s\n", "Copy:");
	print_keys(copy, keys);
	printf("%s\n", "Original:");
	print_keys(tree, keys);

	kvpairs = ptree_to_kvpairs(tree);
	printf("%s", "\n\n\n");
	ft_lstiter(kvpairs, &print_kventry);

	ft_lstdel(&kvpairs, &del_kventry);
	del_tree(tree);
	del_tree(copy);
	free(NULL);
	return (0);
}
