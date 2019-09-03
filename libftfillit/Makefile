# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 11:27:35 by behaudeg          #+#    #+#              #
#    Updated: 2019/05/09 17:28:48 by behaudeg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = libft.h
SRC = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_atoi.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c  ft_strcmp.c ft_strncat.c ft_strncmp.c \
ft_tolower.c ft_toupper.c ft_strstr.c ft_bzero.c ft_memccpy.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strnstr.c ft_memchr.c ft_memcmp.c \
ft_putchar.c ft_putstr.c ft_memalloc.c ft_memdel.c ft_strclr.c ft_strdel.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin_free.c ft_strmap.c \
ft_strnequ.c ft_strnew.c ft_strsub.c ft_strtrim.c ft_putchar_fd.c \
ft_strsplit.c ft_putstr_fd.c ft_putnbr_fd.c ft_putnbr.c ft_putendl_fd.c \
ft_putendl.c ft_itoa.c ft_strmapi.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): $(SRC)
	gcc -Wall -Werror -Wextra -c $(SRC) -I $(INCLUDE)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
