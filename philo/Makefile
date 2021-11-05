# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 08:27:05 by donghyki          #+#    #+#              #
#    Updated: 2021/11/01 19:53:40 by donghyki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS =-Wall -Wextra -Werror
AR=ar
ARFLAGS=cr
NAME = philo
SRCS = \
	main.c \
	philosopher.c \
	utils.c \
	check_valid.c \
	check_time.c \
	free.c \
	philosopher_action.c
OBJ = $(SRCS:.c=.o)
HEADER = .

all: ${NAME}

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) -lpthread

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@ -I$(HEADER)

clean:
	@rm -rf $(OBJ)

fclean:
	@make clean
	@rm -rf ${NAME}

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
