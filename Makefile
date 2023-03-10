# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 21:03:06 by egoncalv          #+#    #+#              #
#    Updated: 2023/03/10 12:46:18 by egoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

NAME = minishell

SRC = 	src/minishell.c \
		src/prompt/prompt.c \
		src/parsing/parsing.c \

OBJ = $(SRC:.c=.o)

LIBS = -lreadline lib/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)
	@echo "Minishell compiled"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

.phony: all clean fclean re bonus
