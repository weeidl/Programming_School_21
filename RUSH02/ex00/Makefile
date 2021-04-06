# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewayn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/21 11:44:15 by ewayn             #+#    #+#              #
#    Updated: 2021/02/21 20:42:40 by dwren            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rush-02

SRCS	= work.c check_dict.c check_nbr.c chekker.c former.c nbr_to_text.c reader.c rush_02.c with3.c
OBJS	= work.o check_dict.o check_nbr.o chekker.o former.o nbr_to_text.o reader.o rush_02.o with3.o
HAND	= dict.h

CC		= gcc
RM		= rm -f
FLAG	= -Wall -Wextra -Werror

.c.o: 
	${CC} ${FLAG} -c $< -o ${<:.c=.o} -I ${HAND}

${NAME} : ${OBJS}
	${CC} ${FLAG} ${OBJS} -o ${NAME}

all: ${NAME}

clean: 
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

norm:
	norminette *.c *.h

re: fclean all

.PHONY: all clean fclean re .c.o
