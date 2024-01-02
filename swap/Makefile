# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:22:19 by rihoy             #+#    #+#              #
#    Updated: 2024/01/02 14:39:24 by rihoy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push.c rev_rota.c rota.c swap.c \
		algo.c error_usage.c ft_split.c main.c \
		stack.c utils_algo.c utils_swap.c \
		sec_utils.c

OBJS = ${SRCS:.c=.o}

OBJS_DIR = objs

OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -fr
GREEN = \033[32;1m
BOLD = \033[1m
RED = \033[31;1m

all : ${NAME}

${NAME} : $(OBJS_DIR) $(OBJS_PATH)
	@(${CC} ${CFLAGS} -o ${NAME} ${OBJS_PATH})
	@echo "$(BOLD)$(GREEN)COMPILATION FINI"

$(OBJS_DIR)/%.o : %.c
	@(${CC} ${CFLAGS} -c $< -o $@)

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

clean :
	@(${RM} $(OBJS_DIR))

fclean : clean
	@(${RM} ${NAME})
	@echo "$(BOLD)$(RED)SUPPRESSION DES DOSSIER."

re : fclean all