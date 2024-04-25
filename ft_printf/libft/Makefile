# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darkwater <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 01:44:05 by darkwater         #+#    #+#              #
#    Updated: 2024/04/19 23:40:56 by lstephen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRC				= ft_atoi.c					\
				  ft_bzero.c				\
				  ft_calloc.c				\
				  ft_isalnum.c				\
				  ft_isalpha.c				\
				  ft_isascii.c				\
				  ft_isdigit.c				\
				  ft_isprint.c				\
				  ft_itoa.c					\
				  ft_memchr.c				\
				  ft_memcmp.c				\
				  ft_memcpy.c				\
				  ft_memmove.c				\
				  ft_memset.c				\
				  ft_putchar_fd.c			\
				  ft_putendl_fd.c			\
				  ft_putnbr_fd.c			\
				  ft_putstr_fd.c			\
				  ft_split.c				\
				  ft_strchr.c				\
				  ft_strdup.c				\
				  ft_striteri.c				\
				  ft_strjoin.c				\
				  ft_strlcat.c				\
				  ft_strlcpy.c				\
				  ft_strlen.c				\
				  ft_strmapi.c				\
				  ft_strncmp.c				\
				  ft_strnstr.c				\
				  ft_strrchr.c				\
				  ft_strtrim.c				\
				  ft_substr.c				\
				  ft_tolower.c				\
				  ft_toupper.c				\
				  ft_lstnew_bonus.c			\
				  ft_lstadd_front_bonus.c	\
				  ft_lstsize_bonus.c		\
				  ft_lstlast_bonus.c		\
				  ft_lstadd_back_bonus.c	\
				  ft_lstdelone_bonus.c		\
				  ft_lstclear_bonus.c		\
				  ft_lstiter_bonus.c		\
				  ft_lstmap_bonus.c			\

OBJS			= $(SRC:.c=.o)

OBJ_OUTPUT		= .output

HEADER			= ./

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -Wpedantic

AR				= ar -crs

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Colours  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

RED				= \033[0;31m

GREEN			= \033[0;32m

NC				= \033[0m

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Messages ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

BEGIN_COMP		= echo "\n ~ ~ ~ $(GREEN)Compiling LIBFT Objects$(NC) ~ ~ ~\n"

LIBFT_COMP		= echo "\n ~ ~ ~ $(GREEN)Compiling LIBFT$(NC) ~ ~ ~\n"

CLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Cleaning all LIBFT object files$(NC) ~ ~ ~\n"

FCLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Removing LIBFT$(NC) ~ ~ ~\n"

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Rules ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

all: $(NAME)

$(NAME): $(OBJ_OUTPUT) $(OBJS)
	@$(LIBFT_COMP)
	@$(AR) $(NAME) $(OBJS)

$(OBJ_OUTPUT):
	@$(BEGIN_COMP)
	@touch $(OBJ_OUTPUT)

%.o: %.c
	@$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

clean:
	@$(RM) $(OBJ_OUTPUT) $(OBJS)

fclean: clean
	@$(FCLEAN_MSG)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
