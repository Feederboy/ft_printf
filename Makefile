# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 13:05:22 by maquentr          #+#    #+#              #
#    Updated: 2021/11/08 14:46:58 by matt             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

INC=ft_printf.h

SRC=ft_printf.c \
	ft_utils.c \
	ft_utils2.c \
	ft_utils3.c \
	ft_utils4.c \
	ft_check_zero_and_prec.c \
	ft_init_and_read_args.c \
	ft_conv_check_args.c \
	ft_conv_d.c \
	ft_conv_u.c \
	ft_conv_p.c \
	ft_conv_p_bis.c \
	ft_conv_X.c \
	ft_conv_X_utils.c \
	ft_conv_X_utils2.c \
	ft_conv_X_set_args.c \
	ft_conv_s.c \
	ft_conv_pct.c \
	ft_conv_xx.c \
	ft_conv_c.c \
	ft_conv_i.c \

OBJ=$(SRC:.c=.o)


%.o: %.c
	$(CC) $(CFLAGS) -c $< $(INC)

$(NAME): $(OBJ)
	ar rcs	$(NAME)	$(OBJ)

all: $(NAME)

bonus:
	@make	all	OBJ="$(OBJ)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
