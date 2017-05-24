# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkalia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 14:12:11 by jkalia            #+#    #+#              #
#*   Updated: 2017/05/24 15:48:15 by jkalia           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		:= filler
CC			:= gcc
#CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -I includes/ -I libft/includes/
CFLAGS		+= -g
LDFLAGS		:= -L libft/ -lft

LIBFT		:= libft/libft.a

FILES		+= main utils
#FILES		+= alloc_wrap


SRC		:= $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ		:= $(SRC:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME)

$(LIBFT):
	@make -C libft

	
$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "\033[32mCreated FILLER\033[0m"

clean:
	@make -C libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\033[32mRemoved FILLER\033[0m"

re: fclean all
