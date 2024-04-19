# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstephen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 02:06:28 by lstephen          #+#    #+#              #
#    Updated: 2023/11/03 22:34:19 by lstephen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

LIBFT_SRC		= ./libft

PRINTF_NAME		= libprintf.a

LIBFT_NAME		= libft.a

SRC				= $(wildcard *.c)

OBJS			= ${SRC:c=o}

HEADER			= ./

CC				= cc

CFLAGS			= -g -Wall -Wextra -Werror

AR				= ar -crs

AR_FINAL		= ar -rs

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Messages ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

BEGIN_LIBFT		= echo "\n ~ ~ ~ Compiling LIBFT ~ ~ ~\n"

BEGIN_COMP		= echo "\n ~ ~ ~ Compiling Objects ~ ~ ~\n"

PROGRAM_COMP	= echo "\n ~ ~ ~ Compiling Program ~ ~ ~\n"

CLEAN_MSG		= echo "\n ~ ~ ~ Cleaning all object files ~ ~ ~\n"

FCLEAN_MSG		= echo "\n ~ ~ ~ Removing Programs ~ ~ ~\n"

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Rules ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

all: ${NAME}

libft:
	@${BEGIN_LIBFT}
	${MAKE} -C ${LIBFT_SRC}
	cp ${LIBFT_SRC}/${LIBFT_NAME} .
	mv ${LIBFT_NAME} ${NAME}
	@${BEGIN_COMP}

%.o: %.c
	${CC} ${CFLAGS} -c -I ${HEADER} $< -o $@

${NAME}: libft ${OBJS}
	${AR_FINAL} ${NAME} ${OBJS}

clean:
	@${CLEAN_MSG}
	rm -f ${OBJS}
	${MAKE} clean -C ${LIBFT_SRC}

fclean: clean
	@${FCLEAN_MSG}
	rm -f ${NAME}
	${MAKE} fclean -C ${LIBFT_SRC}

re: fclean all

.PHONY: all clean fclean re libft LIBFT
