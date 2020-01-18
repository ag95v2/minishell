#include "environment.h"

static char		*concat_key_value(t_list *l)
{
	char	*res;
	char	*key;
	char	*value;
	char	*current;

	if (!l->data)
		return (NULL);
	key = ((t_key_value *)l->data)->key;
	value = (char *)((t_key_value *)l->data)->value;
	res = malloc(ft_strlen(key) + ft_strlen(value));
	if (!res)
		return (NULL);
	current = res;
	while ((*current++ = *key++))
		;
	*current++ = '=';
	while ((*current++ = *value++))
		;
	*current = 0;
	return (res);
}

/*
** Return NULL in case of memory errors
** list is assumed to have entries
*/

static char		**list_to_array(t_list *l)
{
	char	*entry;
	char	**env;
	char	**ret;

	if (!(env = ft_memalloc(sizeof(char *) * (ft_lstlen(l) + 1))))
		return (NULL);
	ret = env;
	while (*l)
	{
		if (!(*env = concat_key_value(l)))
			return (del_array(ret));
		l = l->next;
		env++;
	}
	return (ret);
}

static void		del_list_entry(void *content, size_t content_size)
{
	(void content_size);
	(t_key_value *)content;
	free(content->key);
	free(content->value);
}

/*
** Ptree to char **
** Flatten a prefix tree to NULL-terminated array of strings in 
** format "key=value"
** In case of memory errors, fill memory_ok with 0
*/

char			**to_array(t_env env, int *memory_ok)
{
	t_list	*l;
	char	**env;

	(t_ptree *)env;
	*memory_ok = 1;
	l = ptree_to_kvpairs(tree);
	if (ft_lstlen(l) == 1 && !l->data)
		return (NULL);
	env = list_to_array(l);
	if (!env)
		*memory_ok = 0;
	ft_lstdel(l, &del_list_entry);
	return (env);
}
