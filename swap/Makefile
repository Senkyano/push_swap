# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:22:19 by rihoy             #+#    #+#              #
#    Updated: 2023/12/18 18:14:16 by rihoy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	move/push.c move/rev_rota.c move/rota.c move/swap.c \
		algo.c error_usage.c ft_split.c main.c \
		stack.c utils_algo.c utils_swap.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all