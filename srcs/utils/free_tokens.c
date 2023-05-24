#include "header.h"

void	ft_clean_nextword(t_list **token)
{
	t_list	*tmp;

	if (!(*token))
		return ;
	while ((*token))
	{
		tmp = (*token);
		(*token) = (*token)->next_word;
		free(tmp);
	}
}
void	ft_tokencleaner(t_list **token)
{
	t_list	*tmp;

	if (!token || !*token)
		return ;
	while (*token)
	{
		tmp = *token;
		ft_clean_nextword(&(*token)->next_word);
		*token = (*token)->next;
		free(tmp->content);
		free(tmp);
	}
	free(*token);
    *token =NULL;
}
