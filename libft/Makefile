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

#_Colors_#

GREEN	=	echo "\x1b[32m $1 \x1b[0m $2"
 
PURPLE	=	echo "\x1b[35m $1 \x1b[0m $2"

#_Files_#

NAME	=	libft.a

SRC_DIR =	./srcs/

SRC 	=	$(SRC_DIR)ft_putnbr_fd.c	\
			$(SRC_DIR)ft_putnbr.c		\
			$(SRC_DIR)ft_strclr.c		\
			$(SRC_DIR)ft_strcmp.c		\
			$(SRC_DIR)ft_strequ.c		\
			$(SRC_DIR)ft_strjoin.c		\
			$(SRC_DIR)ft_strjoins.c		\
			$(SRC_DIR)ft_strlen.c		\
			$(SRC_DIR)ft_strnequ.c		\
			$(SRC_DIR)ft_strnew.c		\
			$(SRC_DIR)ft_tolower.c		\
			$(SRC_DIR)ft_toupper.c		\
			$(SRC_DIR)ft_putchar.c		\
			$(SRC_DIR)ft_putchar_fd.c	\
			$(SRC_DIR)ft_putspace.c		\
			$(SRC_DIR)ft_putstr.c		\
			$(SRC_DIR)ft_putstr_fd.c	\
			$(SRC_DIR)ft_putendl.c		\
			$(SRC_DIR)ft_putendl_fd.c	\
			$(SRC_DIR)ft_isdigit.c		\
			$(SRC_DIR)ft_just_alpha.c	\
			$(SRC_DIR)ft_just_num.c		\
			$(SRC_DIR)ft_isalpha.c		\
			$(SRC_DIR)ft_isalnum.c		\
			$(SRC_DIR)ft_isupper.c		\
			$(SRC_DIR)ft_islower.c		\
			$(SRC_DIR)ft_isprint.c		\
			$(SRC_DIR)ft_isascii.c		\
			$(SRC_DIR)ft_strcpy.c		\
			$(SRC_DIR)ft_strcat.c		\
			$(SRC_DIR)ft_strncat.c		\
			$(SRC_DIR)ft_strlcat.c		\
			$(SRC_DIR)ft_strdup.c		\
			$(SRC_DIR)ft_strndup.c		\
			$(SRC_DIR)ft_memset.c		\
			$(SRC_DIR)ft_bzero.c		\
			$(SRC_DIR)ft_memcpy.c		\
			$(SRC_DIR)ft_memccpy.c		\
			$(SRC_DIR)ft_memalloc.c		\
	 		$(SRC_DIR)ft_strchr.c		\
			$(SRC_DIR)ft_strrchr.c		\
			$(SRC_DIR)ft_strstr.c		\
			$(SRC_DIR)ft_atoi.c			\
			$(SRC_DIR)ft_strdel.c		\
			$(SRC_DIR)ft_striter.c		\
			$(SRC_DIR)ft_memdel.c		\
			$(SRC_DIR)ft_itoa.c			\
			$(SRC_DIR)ft_strmap.c		\
			$(SRC_DIR)ft_strmapi.c		\
			$(SRC_DIR)ft_striteri.c		\
			$(SRC_DIR)ft_strtrim.c		\
			$(SRC_DIR)ft_strsub.c		\
			$(SRC_DIR)ft_memmove.c		\
			$(SRC_DIR)ft_memchr.c		\
			$(SRC_DIR)ft_memcmp.c		\
			$(SRC_DIR)ft_strncmp.c		\
			$(SRC_DIR)ft_strncpy.c		\
			$(SRC_DIR)ft_strnstr.c		\
			$(SRC_DIR)ft_strsplit.c		\
			$(SRC_DIR)ft_white_space.c	\
			$(SRC_DIR)get_next_line.c	\
			$(SRC_DIR)my_printf.c		\
			$(SRC_DIR)tabtools.c		\

OBJ 	=	ft_putnbr_fd.o		\
			ft_putnbr.o			\
			ft_strclr.o			\
			ft_strcmp.o			\
			ft_strequ.o			\
			ft_strjoin.o		\
			ft_strjoins.o		\
			ft_strlen.o			\
			ft_strnequ.o		\
			ft_strnew.o			\
			ft_tolower.o		\
			ft_toupper.o		\
			ft_putchar.o		\
			ft_putchar_fd.o		\
			ft_putspace.o		\
			ft_putstr.o			\
			ft_putstr_fd.o		\
			ft_putendl.o		\
			ft_putendl_fd.o		\
			ft_isdigit.o		\
			ft_just_alpha.o		\
			ft_just_num.o		\
			ft_isalpha.o		\
			ft_isalnum.o		\
			ft_isupper.o		\
			ft_islower.o		\
			ft_isprint.o		\
			ft_isascii.o		\
			ft_strcpy.o			\
			ft_strcat.o			\
			ft_strncat.o		\
			ft_strlcat.o		\
			ft_strdup.o			\
			ft_strndup.o		\
			ft_memset.o			\
			ft_bzero.o			\
			ft_memcpy.o			\
			ft_memccpy.o		\
			ft_memalloc.o		\
	 		ft_strchr.o			\
			ft_strrchr.o		\
			ft_strstr.o			\
			ft_atoi.o			\
			ft_strdel.o			\
			ft_striter.o		\
			ft_memdel.o			\
			ft_itoa.o			\
			ft_strmap.o			\
			ft_strmapi.o		\
			ft_striteri.o		\
			ft_strtrim.o		\
			ft_strsub.o			\
			ft_memmove.o		\
			ft_memchr.o			\
			ft_memcmp.o			\
			ft_strncmp.o		\
			ft_strncpy.o		\
			ft_strnstr.o		\
			ft_strsplit.o		\
			ft_white_space.o	\
			get_next_line.o		\
			my_printf.o			\
			tabtools.o			\

all: $(NAME)

$(NAME): $(SRC)
	@gcc  -I ../includes -c -Wall -Werror -Wextra $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
.PHONY: clean fclean 
