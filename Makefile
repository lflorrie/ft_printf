# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 22:08:47 by lflorrie          #+#    #+#              #
#    Updated: 2020/12/25 01:24:07 by lflorrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Werror -Wextra -Wall

SRC=	ft_printf.c \
	parser.c \
	ft_charprocessing.c \
	ft_intprocessing.c \
	ft_pointerprocessing.c \
	ft_processing_flags.c \
	ft_itoa16.c \
	ft_uitoa.c 

OBJ=$(SRC:.c=.o)

NAME=libftprintf.a

%.o:%.c
	gcc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C libft/
	ar -rcsT $(NAME) $? libft/libft.a

all: $(NAME)

test:
	gcc $(SRC) tests.c -Llibft -lft
test2:
	gcc -o test main.c -L. -lftprintf
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME) && $(MAKE) fclean -C libft/
re: fclean all

.PHONY: all clean fclean re
