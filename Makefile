# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 05:38:22 by yrhiba            #+#    #+#              #
#    Updated: 2023/06/01 08:37:09 by rghouzra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS_BUILTINS = srcs/builtins/cd/cd.c \
				srcs/builtins/echo/echo.c \
				srcs/builtins/env/env.c \
				srcs/builtins/export/export.c \
				srcs/builtins/exit/exit.c

SRCS_FOOTER =	srcs/presh/presh.c \
				srcs/presh/presh_utils.c \
				srcs/clear/my_list_data_clear.c

SRCS_HEADER =	srcs/evaluator/evaluator.c \
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
				srcs/utils/signal_utils.c\
				srcs/utils/readinput.c \
				srcs/utils/getcmdfullpath.c \
				srcs/utils/ifbuiltinbreak.c \
				srcs/utils/export_sort.c \
				srcs/utils/contrui_env.c

SRCS =	mnsh.c $(SRCS_BUILTINS) $(SRCS_HEADER) $(SRCS_FOOTER)

INCS =  incs/header.h \
		incs/footer.h \
		incs/mnsh.h \
		incs/builtins/cd.h \
		incs/builtins/echo.h \
		incs/builtins/env.h \
		incs/builtins/export.h \
		incs/builtins/exit.h \
		incs/footer/presh.h \
		incs/footer/clear.h \
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

COMPILER = cc

OBJS = $(addprefix $(ODIR), $(SRCS:.c=.o))

FLAGS = -Wall -Wextra -g #-Werror #-fsanitize=address

LIBSTR = libs/libmystr/libmystr.a

LIBLIST = libs/libmylist/libmylist.a

LIBFT = libs/libft/libft.a

USER = $(shell whoami)

ifeq ($(USER), rghouzra)
	rlpath = /Volumes/REDA/.brew/opt/readline
else
	rlpath = $(shell brew --prefix readline)
endif

RL = -L$(rlpath)/lib -lreadline -I$(rlpath)/include

$(NAME) : $(OBJS) $(LIBLIST) $(LIBSTR) $(LIBFT)
	$(COMPILER) $(FLAGS) $(OBJS) $(LIBLIST) $(LIBSTR) $(LIBFT) -o $(NAME) $(RL)

$(LIBLIST) :
	make -C libs/libmylist

$(LIBSTR) :
	make -C libs/libmystr

$(LIBFT) :
	make -C libs/libft

$(ODIR)%.o : %.c $(INCS)
	@mkdir -p $(dir $@)
	$(COMPILER) $(FLAGS) -c $< -o $@ $(INCLINK) -I$(rlpath)/include

all : $(NAME)

clean :
	make fclean -C libs/libmylist
	make fclean -C libs/libmystr
	make fclean -C libs/libft
	rm -rf $(ODIR) *.dot .vscode

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
