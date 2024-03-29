# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 10:34:24 by behaudeg          #+#    #+#              #
#    Updated: 2019/09/09 15:26:16 by leblocqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

FILE	=	backtrack.c\
			checker.c\
			init_checker.c\
			main.c\
			map.c\
			tetriminos.c
			
SRC		= $(addprefix src/, $(FILE))

OBJ		= $(patsubst src/%.c,./%.o,$(SRC))

INCLUDE	= includes/fillit.h \
		  includes/libft.h \

.SILENT:

$(NAME): $(OBJ)
	gcc -g -Wall -Werror -Wextra $(OBJ) -I includes libftfillit/libft.a -o $(NAME)
./%.o: src/%.c
	gcc -g -Wall -Wextra -Werror -c $< -o $@

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
