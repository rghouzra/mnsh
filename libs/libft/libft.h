/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:54:04 by rghouzra          #+#    #+#             */
/*   Updated: 2023/05/24 21:54:53 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SQ 39
# define AND 38
# define DQ 34
# define OPAR 40
# define CPAR 41
# define SP 32
# define SC 59
# define WC 42
# define REDIR_O 62
# define REDIR_I 60
# define ASSIGN 61
# define DASH 45
# define SHARP 35
# define nullptr 0x0

typedef enum TokenType
{
	WORD = 1 << 0,
	STRING = 1 << 2,
	STR_SQ = 1 << 3,
	PIPE = 1 << 4,
	AMP = 1 << 5,
	redir_i = 1 << 6,
	redir_o = 1 << 7,
	opar = 1 << 8,
	cpar = 1 << 9,
	heredoc_i = 1 << 10,
	append_o = 1 << 11,
	PIPE_LINE = WORD | PIPE | WORD,
	AND_CMD_CHAIN = WORD | (AMP & AMP) | WORD,
	OR_CMD_CHAIN = WORD | (PIPE & PIPE) | WORD,
	NONE = -1
}					t_tokentype;

typedef struct s_list
{

	t_tokentype		type;
	void			*content;
	struct s_list	*next_word;
    int sep;
	struct s_list	*next;

}					t_list;

typedef struct s_ast
{
	int				type;
	void			*value;
	t_list			*next_word;
	struct s_ast	*left;
	int				side;
	struct s_ast	*right;

}					t_ast;

void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_strlen(const char *s);
int					ft_strcmp(char *s1, char *s2);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
char				*ft_free(char **s);
int					ft_isalnum(int c);
int					ft_isprint(int c);
char				**ft_split(char const *s, char c);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				del(void *content);
char				*ft_itoa(int n);
void				ft_bzero(void *s, size_t n);
void				*ft_malloc(size_t byte);
int					ft_atoi(const char *nptr);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
t_list				*ft_tokennew(void *content, t_tokentype type);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strdup(const char *s1);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2, int option);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
void				*ft_calloc(size_t nelem, size_t elsize);
char				*strrchr(const char *s, int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strrchr(const char *s, int c);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				show_error(char *s, int exit_status);
pid_t				ft_fork();
void				ft_pipe(int fd[]);

#endif
