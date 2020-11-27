# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 22:08:47 by lflorrie          #+#    #+#              #
#    Updated: 2020/11/26 12:28:39 by lflorrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Werror -Wextra -Wall

SRC=	ft_printf.c \
	parser.c \
	ft_itoa16.c

OBJ=$(SRC:.c=.o)

NAME=libftprintf.a

%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rcsT $(NAME) $(OBJ) libft/libft.a
all: $(NAME)
	$(MAKE) -C libft/
test:
	gcc $(SRC) tests.c -Llibft -lft
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME) && $(MAKE) clean -C libft/
re: fclean all

.PHONY: all clean fclean $(NAME) re
