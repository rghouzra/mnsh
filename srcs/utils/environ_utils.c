#include "header.h"

void	ft_lstenvaddback(t_env **lst, t_env *new)
{
	t_env	*copy;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	copy = *lst;
	while (copy->next)
		copy = copy->next;
	copy->next = new;
}

void get_key_and_value(t_env *node, char *src)
{
	int i;

	i = -1;
	while(src[++i])
		if(src[i] == '=')
			break;
	node->key = ft_substr(src, 0, i);
	node->value = ft_strdup(src + i);
}

t_env	*ft_newenv(char *var)
{
	t_env	*node;

	if (!var)
		return (NULL);
	node = ft_malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	get_key_and_value(node, var);
	node->next = NULL;
	return (node);
}

void	init_global(char **env, t_global *minishell)
{
	int i;

	i = 0;
	(minishell)->environ = NULL;
	if (!env || !*env)
		return ;
	while (env[i])
	{
		ft_lstenvaddback(&minishell->environ, ft_newenv(env[i]));
		i++;
	}
}