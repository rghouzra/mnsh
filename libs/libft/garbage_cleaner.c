#include "libft.h"

void	env_cleaner(t_env **lst, void (*del)(void *))
{
	t_env *tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	free(*lst);
}