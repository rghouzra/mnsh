#ifndef UTILS_H
# define UTILS_H

# include "header.h"
# include <stdbool.h>
typedef struct s_queue
{
	void			*content;
	t_tokentype		type;
	t_list			*next_word;
	struct s_queue	*head;
	struct s_queue	*next;
	struct s_queue	*tail;
}					t_queue;
typedef struct s_poped
{
	t_tokentype		type;
	void			*content;
	t_list			*next_word;
}					t_poped;
bool				enqueue(t_queue **q, char *value, enum TokenType type,
						t_list *next_word);
void				init_global(char **env, t_global *minishell);
int					get_token_priority(t_list *q);
t_env				*ft_newenv(char *var);
void				ft_lstenvaddback(t_env **lst, t_env *new);
bool				dequeue(t_queue **q);
void				init_queue(t_queue *q);
t_poped				pop(t_list **p);
bool				push(t_list **p, void *value, t_tokentype type,
						t_list *next_word);
int					peek(t_list *s);
void				ft_tokencleaner(t_list **token);
char				*get_path(t_env *env);
void				tree_cleaner(t_ast **tree);
#endif