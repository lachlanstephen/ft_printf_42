# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstephen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 02:06:28 by lstephen          #+#    #+#              #
#    Updated: 2024/04/19 23:43:42 by lstephen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRC				= ft_printf.c			\
				  ft_printf_char.c		\
				  ft_printf_hex.c		\
				  ft_printf_int.c		\
				  ft_printf_ptr.c		\
				  ft_printf_str.c		\
				  ft_printf_unsigned.c	\

#BONUS			= 

OBJS			= $(SRC:.c=.o)

HEADER			= ./

LIBFT			= libft.a

LIBFT_DIR		= ./libft/

LIBFT_PRE		= $(addprefix $(LIBFT_DIR), $(LIBFT))

CC				= cc

CFLAGS			= -g -Wall -Wextra -Werror -Wpedantic

AR				= ar -crs

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Colours  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

RED				= \033[0;31m

GREEN			= \033[0;32m

NC				= \033[0m

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Messages ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

BEGIN_COMP		= echo "\n ~ ~ ~ $(GREEN)Compiling Objects$(NC) ~ ~ ~\n"

PROGRAM_COMP	= echo "\n ~ ~ ~ $(GREEN)Compiling Program$(NC) ~ ~ ~\n"

CLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Cleaning all object files$(NC) ~ ~ ~\n"

FCLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Removing Programs$(NC) ~ ~ ~\n"

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Rules ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

all: $(NAME)

$(NAME): $(LIBFT_PRE)  $(OBJS)
	@$(PROGRAM_COMP)
	$(AR) $(NAME) $(OBJS)

$(LIBFT_PRE):
	@$(BEGIN_LIBFT)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_PRE) .
	@mv $(LIBFT) $(NAME)
	@$(BEGIN_COMP)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(CLEAN_MSG)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(FCLEAN_MSG)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
