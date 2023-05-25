# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 11:42:14 by yrhiba            #+#    #+#              #
#    Updated: 2023/05/25 20:00:21 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS_BUILTINS = srcs/builtins/cd/cd.c \
				srcs/builtins/echo/echo.c

SRCS_FOOTER =	srcs/presh/presh.c

SRCS_HEADER =	srcs/evaluator/evaluator.c \
				srcs/executor/eval_tree_utils.c \
				srcs/executor/eval_tree.c \
				srcs/executor/executor_utils.c \
				srcs/executor/handle_redir.c \
				srcs/lexer/lexer_utils.c \
				srcs/lexer/lexer.c \
				srcs/parser/parser_utils.c \
				srcs/parser/parser.c \
				srcs/tokenizer/tokenizer_utils.c \
				srcs/tokenizer/tokenizer_utils2.c \
				srcs/tokenizer/tokenizer.c \
				srcs/tokenizer/tokenizer2.c \
				srcs/utils/free_tokens.c \
				srcs/utils/queue_utils.c \
				srcs/utils/stack_utils.c \
				srcs/utils/garbage_cleaner.c\
				srcs/utils/utils_minishell.c\
				srcs/utils/readinput.c

SRCS =	mnsh.c $(SRCS_BUILTINS) $(SRCS_HEADER) $(SRCS_FOOTER)

INCS =  incs/header.h \
		incs/footer.h \
		incs/mnsh.h \
		incs/builtins/cd.h \
		incs/builtins/echo.h \
		incs/footer/presh.h \
		incs/header/evaluator.h \
		incs/header/executor.h \
		incs/header/lexer.h \
		incs/header/minishell.h \
		incs/header/parser.h \
		incs/header/tokenizer.h \
		incs/header/utils.h

INCLINK =	-I . -I incs \
			-I libs/libmylist \
			-I libs/libmystr \
			-I libs/libft

ODIR = objs/

OBJS = $(addprefix $(ODIR), $(SRCS:.c=.o))

FLAGS = -Wall -Wextra -Werror

LIBSTR = libs/libmystr/libmystr.a

LIBLIST = libs/libmylist/libmylist.a

LIBFT = libs/libft/libft.a

$(NAME) : $(OBJS) $(LIBLIST) $(LIBSTR) $(LIBFT)
	cc $(FLAGS) $(OBJS) $(LIBLIST) $(LIBSTR) $(LIBFT) -lreadline -o $(NAME)

$(LIBLIST) :
	make -C libs/libmylist

$(LIBSTR) :
	make -C libs/libmystr

$(LIBFT) :
	make -C libs/libft

$(ODIR)%.o : %.c $(INCS)
	@mkdir -p $(dir $@)
	cc $(FLAGS) -c $< -o $@ $(INCLINK)

all : $(NAME)

clean :
	make fclean -C libs/libmylist
	make fclean -C libs/libmystr
	make fclean -C libs/libft
	rm -rf $(ODIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
