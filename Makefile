# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 15:55:57 by rihoy             #+#    #+#              #
#    Updated: 2023/12/07 12:14:08 by rihoy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_case.c ft_split.c number.c \
		algo.c check.c ft_case2.c \
		push.c rev_rota.c rotate.c ssab.c

OBJS = ${SRCS:.c=.o}

CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = lib_push_swap.a

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean :
	rm -f ${NAME}

re : fclean ${NAME}