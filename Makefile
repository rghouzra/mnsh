# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 05:38:22 by yrhiba            #+#    #+#              #
#    Updated: 2024/02/07 15:17:13 by rghouzra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS_BUILTINS = srcs/builtins/cd/cd.c \
				srcs/builtins/echo/echo.c \
				srcs/builtins/env/env.c \
				srcs/builtins/export/export.c \
				srcs/builtins/export/export_utils.c \
				srcs/builtins/exit/exit.c \
				srcs/builtins/unset/unset.c \
				srcs/builtins/pwd/pwd.c

SRCS_PRESH =	srcs/presh/presh.c \
				srcs/presh/presh_utils.c

SERCS_CLEAR =	srcs/clear/my_list_data_clear.c

SRCS_FOOTER =	srcs/expand_utils/envgetvalue.c \
				srcs/expand_utils/env_var_exist.c \
				srcs/expand_utils/env_var_update.c \
				srcs/expand_utils/export_var_exist.c \
				srcs/expand_utils/export_var_update.c \
				srcs/expand_utils/expand_term.c \
				srcs/expand_utils/expand_term_utils.c \
				srcs/expand_utils/remove_quotes.c \
				srcs/expand_utils/expand.c \
				srcs/wildcard/expand_wildcard.c

SRCS_UTILS =	srcs/utils/free_tokens.c \
				srcs/utils/queue_utils.c \
				srcs/utils/stack_utils.c \
				srcs/utils/garbage_cleaner.c\
				srcs/utils/utils_minishell.c\
				srcs/utils/signal_utils.c\
				srcs/utils/readinput.c \
				srcs/utils/getcmdfullpath.c \
				srcs/utils/ifbuiltinbreak.c \
				srcs/utils/export_sort.c \
				srcs/utils/wildcard_utils.c \
				srcs/utils/contrui_env.c \
				srcs/utils/exit_status.c \
				srcs/utils/contrui_cmnds.c \
				srcs/utils/read_heredoc.c \
				srcs/utils/heredoc_utils.c \
				srcs/utils/get_list_pos.c \
				srcs/utils/free_string.c \
				srcs/utils/remove_quotes.c

SRCS_HEADER =	srcs/executor/eval_tree.c \
				srcs/executor/executor_utils.c \
				srcs/executor/handle_redir.c \
				srcs/executor/redirection_utils.c \
				srcs/lexer/lexer_utils.c \
				srcs/lexer/lexer.c \
				srcs/parser/parser_utils.c \
				srcs/parser/parser.c \
				srcs/tokenizer/tokenizer_utils.c \
				srcs/tokenizer/tokenizer_utils2.c \
				srcs/tokenizer/tokenizer.c \
				srcs/tokenizer/tokenizer2.c \
				srcs/tokenizer/tokenizer3.c \
				srcs/tokenizer/tokenizer3_utils.c \
				srcs/tokenizer/analyze_token.c \
				$(SRCS_UTILS)

SRCS =	mnsh.c $(SRCS_BUILTINS) $(SRCS_PRESH) $(SERCS_CLEAR) $(SRCS_HEADER) $(SRCS_FOOTER)

INCS_BUILTINS =	incs/builtins/cd.h \
				incs/builtins/echo.h \
				incs/builtins/env.h \
				incs/builtins/export.h \
				incs/builtins/exit.h \
				incs/builtins/unset.h \
				incs/builtins/pwd.h

INCS =	$(INCS_BUILTINS) \
		incs/header.h \
		incs/footer.h \
		incs/mnsh.h \
		incs/footer/presh.h \
		incs/footer/clear.h \
		incs/footer/expand.h \
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

FLAGS = -Wall -Wextra

LIBSTR = libs/libmystr/libmystr.a

LIBLIST = libs/libmylist/libmylist.a

LIBFT = libs/libft/libft.a
READLINE = 1
USER = $(shell whoami)

OS = $(shell uname)
ifeq ($(OS), Linux)
	FLAGS = -Wall -Wextra -g
else
	rlpath = $(shell brew --prefix readline)
	ifeq ($(wildcard $(rlpath)),)
		@echo "Error: readline library not found"
		READLINE = 0
	endif
endif

RL = -L$(rlpath)/lib -lreadline -I$(rlpath)/include

$(NAME) : $(OBJS) $(LIBLIST) $(LIBSTR) $(LIBFT)
	$(COMPILER) $(FLAGS) $(OBJS) $(LIBLIST) $(LIBSTR) $(LIBFT) -D READLINE -o $(NAME) $(RL)

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
