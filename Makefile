# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 10:34:24 by behaudeg          #+#    #+#              #
#    Updated: 2019/06/28 10:34:26 by behaudeg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

FILE	=	backtrack.c\
			checker.c\
			checker2.c\
			main.c\
			map.c\
			tetriminos.c
			
SRC		= $(addprefix src/, $(FILE))

OBJ		= $(patsubst src/%.c,./%.o,$(SRC))

INCLUDE	= includes/fillit.h \
		  includes/libft.h \

.SILENT:

$(NAME): $(OBJ)
	gcc -Wall -Werror -Wextra $(OBJ) -I includes libftfillit/libft.a -o $(NAME)
./%.o: src/%.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	/bin/rm -rf *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all