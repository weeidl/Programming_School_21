# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewayn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 04:38:55 by ewayn             #+#    #+#              #
#    Updated: 2021/02/14 20:26:28 by ewayn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= srcs/ft_putchar.c srcs/ft_swap.c \
		srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

INCLUDE = includes/ft.h

OBJECT	= ${SRCS:.c=.o}

RM		= rm -f

COMP	= cc -Wall -Wextra -Werror -c


AR 		= ar rc

.c.o:
			${COMP} $< -o ${<:.c=.o} -I ${INCLUDE}

${NAME}:	${OBJECT}
			${AR} ${NAME} ${OBJECT}
			
all:		${NAME}

clean:
			${RM} ${OBJECT}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all fclean clean re
