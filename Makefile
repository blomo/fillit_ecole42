# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 18:38:15 by dheredat          #+#    #+#              #
#    Updated: 2019/11/01 16:11:17 by dheredat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJ = main_push.o val_push.o grep_push.o core_push.o
INC = fillit.h
LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC)	$(FLAGS)	$(OBJ)	-o	$(NAME)	$(LIB)

$(LIB):
	make -C ./libft re

$(OBJ): %.o: %.c
	$(CC) $(FLAGS) -c $< -I $(INC) -o $@

clean:
	rm -f $(OBJ)
	make -C ./libft clean
	
fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all