#include "header.h"

char	*get_path(t_env *env)
{
	if (!env)
		return (NULL);
	while (env)
	{
		if (!ft_strcmp(env->key, "PATH"))
			break ;
		env = env->next;
	}
	if (!env)
		return (NULL);
	return (env->value);
}