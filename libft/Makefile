# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschenk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 15:03:29 by aschenk           #+#    #+#              #
#    Updated: 2014/11/21 16:08:43 by aschenk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

H_DIR = includes/
C_DIR = ./
O_DIR = o/

FLAGS = -Wall -Wextra -Werror -O2

C_FILES = $(shell ls -1 $(C_DIR) | grep "\.c")

O_FILES = $(addprefix $(O_DIR),$(C_FILES:.c=.o))

all: $(NAME)

$(NAME): $(O_FILES)
		@ar rc $@ $^ && printf "\033[0;32m" || printf "\033[0;31m"
			@printf "%-24s\033[1;30m<<--\033[0;0m\n" "$@"
				@ranlib $@

$(O_DIR)%.o: $(C_DIR)%.c
		@mkdir $(O_DIR) 2> /dev/null || echo "" > /dev/null
			@gcc $(FLAGS) -I$(H_DIR) -o $@ -c $< && printf "\033[0;0m%-24s\033[1;30m-->>	\033[0;32m$@\033[0;0m\n" "$<" || (printf "\033[0;0m%-24s\033[1;30m-->>	\033[0;31m$@\033[0;0m\n" "$<" && exit 1)

debug: _debug all clean

clean:
		@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
			@rmdir $(O_DIR) 2> /dev/null || echo "" > /dev/null

fclean: clean
		@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re: fclean all

_debug:
		$(eval FLAGS = -Wall -Wextra -g)

.PHONY: all debug clean fclean re _debug
