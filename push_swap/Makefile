# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 19:46:09 by calmouht          #+#    #+#              #
#    Updated: 2023/09/17 00:50:55 by calmouht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

GCC = -Wall -Wextra -Werror

OBJECTS = pushmain.o parse.o sort.o utils.o utils2.o utils3.o rules.o \
		rules2.o rules3.o stack_fill.o utils4.o sort_smaller.o \

B_OBJECTS = get_next_line.o  checker.o b_rules.o b_rules2.o b_rules3.o utils3.o utils.o utils2.o rules.o \
		rules2.o rules3.o parse.o sort.o stack_fill.o utils4.o \

SRCS =	pushmain.c parse.c sort.c utils.c utils2.c utils3.c rules.c \
		rules2.c rules3.c stack_fill.c utils4.c sort_smaller.c \

BONUS =  get_next_line.c  checker.c b_rules.c b_rules2.c b_rules3.c utils3.c utils.c utils2.c rules.c \
		rules2.c rules3.c parse.c sort.c stack_fill.c utils4.c \

BONIF = checker

LIBFT = ./libft/libft.a

%.o : %.c
	$(CC) $< $(GCC) -c -o $@

all: ${NAME}

$(LIBFT) :
	$(MAKE) -C libft

${NAME}: $(LIBFT) ${OBJECTS}
	${CC} ${GCC} ${SRCS} ${LIBFT} -o ${NAME}

bonus : $(LIBFT) ${B_OBJECTS}
	${CC} ${GCC} ${BONUS} ${LIBFT} -D BONUS -o ${BONIF}

clean:
	make clean -C ./libft/
	rm -rf ${OBJECTS}

fclean: clean
	rm -rf ${OBJECTS} ${NAME} ${LIBFT} $(B_OBJECTS)
	rm -rf ${BONIF}

re: fclean all
