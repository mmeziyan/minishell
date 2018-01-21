# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/13 18:15:03 by mmeziyan          #+#    #+#              #
#    Updated: 2017/02/28 20:01:20 by mmeziyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	minishell

SRC		=	srcs/main.c				\
			srcs/tools.c			\
			srcs/list.c				\
			srcs/env.c				\
			srcs/builtins_0.c		\
			srcs/builtins_1.c		\
			srcs/builtins_2.c		\
			srcs/execute.c			\
			srcs/while.c			\
			srcs/signaux.c			\

FLAGS	=	-Wall -Wextra -Werror

OBJ	=		main.o				\
			tools.o				\
			list.o				\
			env.o				\
			builtins_0.o		\
			builtins_1.o		\
			builtins_2.o		\
			execute.o			\
			while.o				\
			signaux.o			\

OBJS	=	$(addprefix objs/, $(OBJ))

all: $(NAME)

%.o : %.c
	gcc -c -o $@ $^

$(NAME): $(SRC)
	@echo mmeziyan > auteur
	@make -C ./libft all
	@gcc $(FLAG) -c $(SRC) -I includes/
	@if [ ! -r "objs/" ]; then mkdir objs/; fi
	@mv $(OBJ) objs/
	@gcc libft/libft.a $(OBJS) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@make -C ./libft clean
	@if [ -r "objs/" ]; then /bin/rm -r objs/; fi

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all

.PHONY: clean fclean
