# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 21:03:06 by egoncalv          #+#    #+#              #
#    Updated: 2023/03/27 16:14:39 by egoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

NAME = minishell

SRC = 	src/minishell.c \
		src/prompt/prompt.c \
		src/parsing/parsing.c \
		src/parsing/args_split.c \
		src/parsing/utils.c \
		src/parsing/token_list.c \
		src/errors/errors.c \

OBJ = $(SRC:.c=.o)

LIBFT_OBJ = libft/*.o

LIBS = -lreadline

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C libft bonus
	@gcc $(CFLAGS) $(LIBS) $(OBJ) $(LIBFT_OBJ) -o $(NAME)
	@echo "Minishell compiled"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	@$(MAKE) --no-print-directory -C libft clean
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) --no-print-directory -C libft fclean
	@rm -rf $(LIBFT_OBJ)

re: fclean $(NAME)

.phony: all clean fclean re bonus
