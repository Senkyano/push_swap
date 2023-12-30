# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:22:19 by rihoy             #+#    #+#              #
#    Updated: 2023/12/29 14:11:35 by rihoy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	move/push.c move/rev_rota.c move/rota.c move/swap.c \
		algo.c error_usage.c ft_split.c main.c \
		stack.c utils_algo.c utils_swap.c \
		sec_utils.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f
GREEN = \033[32;1m
BOLD = \033[1m
RED = \033[31;1m

all : ${NAME}

${NAME} : ${OBJS}
	@(${CC} ${CFLAGS} -o ${NAME} ${OBJS})
	@echo "$(BOLD)$(GREEN)COMPILATION FINI"

%.o : %.c
	@(${CC} ${CFLAGS} -c $< -o $@)

clean :
	@(${RM} ${OBJS})

fclean : clean
	@(${RM} ${NAME})
	@echo "$(BOLD)$(RED)SUPPRESSION DES DOSSIER."

re : fclean all