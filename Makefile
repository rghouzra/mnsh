# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 11:42:14 by yrhiba            #+#    #+#              #
#    Updated: 2023/05/24 23:07:19 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS_BUILTINS = srcs/builtins/cd/cd.c \
				srcs/builtins/echo/echo.c \

SRCS_FOOTER = srcs/presh/presh.c

SRCS_HEADER = 

SRCS =	mnsh.c \
		$(SRCS_BUILTINS) $(SRCS_HEADER) $(SRCS_FOOTER)

OTHER_INCS =	incs/builtins/cd.h \
				incs/builtins/echo.h \
				incs/footer/presh.h \
				incs/header/minishell.h \
				incs/header/utils.h \
				incs/header/parser.h \
				incs/header/lexer.h \
				incs/header/tokenizer.h

INCS =  incs/header.h \
		incs/footer.h \
		incs/mnsh.h \
		$(OTHER_INCS)

INCLINK =	-I . -I incs \
			-I libs/libmylist \
			-I libs/libmystr \
			-I libs/libft

ODIR = objs/

OBJS = $(addprefix $(ODIR), $(SRCS:.c=.o))

FLAGS = -Wall -Wextra #-Werror

LIBSTR = libs/libmystr/libmystr.a

LIBLIST = libs/libmylist/libmylist.a

LIBFT = libs/libft/libft.a

$(NAME) : $(OBJS) $(LIBLIST) $(LIBSTR) $(LIBFT)
	cc $(FLAGS) $(OBJS) $(LIBLIST) $(LIBSTR) -o $(NAME)

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
