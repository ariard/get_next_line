# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 22:56:07 by ariard            #+#    #+#              #
#    Updated: 2016/11/21 23:02:41 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC= main.c\
	get_next_line.c\

OUT= main.o\
	 get_next_line.o\

HEADER= get_next_line.h

FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C srcs/get_next_line.c
	gcc -c $(FLAGS) $(SRC)
	gcc $(OUT) -o $(NAME) -I $(HEADER)

clean:
	rm -f $(OUT)

fclean: clean
	rm -f $(NAME)

re: fclean all
