# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/17 19:05:27 by hyuyoo            #+#    #+#              #
#    Updated: 2020/06/18 00:29:55 by tae-kim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= *.c
INCS	= *.h
OBJ		= ${SRCS.c=.o}

${NAME} :
	${CC} ${CFLAGS} ${SRCS} -o $@ -I ${INCS}

all : ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
