# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afanneau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 15:10:35 by afanneau          #+#    #+#              #
#    Updated: 2017/02/11 19:00:46 by afanneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SOURCES = print.c \
		  init.c \
		  event.c \
		  main.c \
		  write.c \
		  operation.c

OBJECTS = print.o \
		  init.o \
		  event.o \
		  main.o \
		  write.o \
		  operation.o

all : $(NAME)

$(NAME) :
	make -C libft/ && make -C libft/ clean
	make -C minilibx/
	gcc -Wall -Wextra -Werror -I libft/includes -c $(SOURCES) -O2
	gcc -o $(NAME) $(OBJECTS) -I libft/includes -L libft/ -lft minilibx/libmlx.a -framework OpenGL -framework AppKit -Ofast -march=sandybridge

clean :
	rm -f  $(OBJECTS)
	make -C libft/ clean

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
