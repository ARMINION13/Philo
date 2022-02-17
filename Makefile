# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 15:23:37 by rgirondo          #+#    #+#              #
#    Updated: 2021/12/04 20:25:43 by rgirondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

CC=gcc

CFLAGS=-Wall -Wextra -Werror

HEADER= ./philo.h ./ft_printf/ft_printf.h

RM=rm -f

SRC= ./ft_atoi.c ./ft_strchr.c ./philo.c ./utils.c ./routine.c ./threads.c ./utils2.c

OBJ=$(SRC:%.c=%.o)

all:$(NAME)

$(NAME): $(OBJ) $(HEADER)
		cd ./ft_printf/ && make
		$(CC) $(CFLAGS) -L ./ft_printf/ -lftprintf\
		-o $(NAME) $(OBJ)

clean:
		cd ./ft_printf/ && make fclean
		$(RM) $(OBJ)

fclean: clean
		$(RM)
		rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
