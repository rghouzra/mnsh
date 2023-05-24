#include "header.h"

void	tree_cleaner(t_ast **tree)
{
	if (!*tree)
		return ;
	tree_cleaner(&(*tree)->left);
	tree_cleaner(&(*tree)->right);
	free((*tree)->value);
	free(*tree);
}
