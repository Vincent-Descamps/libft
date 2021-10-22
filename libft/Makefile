# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 09:44:36 by vdescamp          #+#    #+#              #
#    Updated: 2021/10/22 14:07:51 by vdescamp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJ}
		ar rc ${NAME} ${OBJ}
		ranlib ${NAME}

all : ${NAME}

clean :
		${RM} ${OBJ}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re
