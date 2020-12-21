# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 22:08:47 by lflorrie          #+#    #+#              #
#    Updated: 2020/12/09 22:51:11 by lflorrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Werror -Wextra -Wall

SRC=	ft_printf.c \
	parser.c \
	ft_itoa16.c \
	ft_uitoa.c

OBJ=$(SRC:.c=.o)

NAME=libftprintf.a

%.o:%.c
	gcc -c $(CFLAGS) $< -o $@
lib:
	$(MAKE) -C libft/

$(NAME): lib $(OBJ)
	ar -rcs $(NAME) $(OBJ) libft/libft.a
all: $(NAME)

test:
	gcc $(SRC) tests.c -Llibft -lft
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME) && $(MAKE) fclean -C libft/
re: fclean all

.PHONY: all clean fclean $(NAME) re
