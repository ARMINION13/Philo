# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 15:23:37 by rgirondo          #+#    #+#              #
#    Updated: 2021/10/26 17:55:27 by rgirondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

HEADER=./ft_printf.h

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC= ./ft_atoi.c ./ft_flags.c ./ft_itoa.c ./ft_printf.c ./ft_putchar_fd.c \
	./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_strchr.c ./ft_strdup.c ./ft_strlen.c\
	./ft_strncmp.c ./ft_types_flags.c ./ft_types_flags2.c ./memadd_if.c\
	./nbr_if.c ./pf_functions.c ./str_if.c ./x_if.c

OBJ=$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		$(CC) $(CFLAGS) -c $(SRC)
		ar -rcs $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ) $(OBJ2)

fclean: clean
		$(RM)
		rm *.a

re: fclean all

.PHONY: all clean fclean re
