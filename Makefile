# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 11:18:32 by anasinda          #+#    #+#              #
#    Updated: 2025/12/27 05:44:34 by anasinda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
RM = rm -f
AR = ar rcs

SRCS = ft_printf.c src/ft_putstr.c src/ft_putsigned.c src/ft_putptr.c src/ft_putnbr.c src/ft_puthex.c src/ft_putchar.c src/ft_ptr_check.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	@echo "---> Making object files! <---"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\n"

clean:
	@echo "---> Removing object files ^__^ <---"
	$(RM) $(OBJS)
	@echo "\n"

fclean: clean
	@echo "---> Removing EVERYTHING o__o <---"
	$(RM) $(NAME)
	@echo "\n"

re: fclean all
	@echo "---> Removed EVERYTHING and created from SCRATCH :D <---"
	@echo "\n"

.PHONY: clean fclean re
