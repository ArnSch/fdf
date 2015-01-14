#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschenk <marvin@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 17:52:57 by aschenk           #+#    #+#              #
#    Updated: 2015/01/12 17:19:05 by aschenk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			fdf

CC =			gcc
FLAGS =			-Wall -Werror -Wextra -g
LIBFT =			"libft/"
X11 =			"/usr/X11/lib"

INC_FLAGS =		-I $(LIBFT)
LIB_FLAGS =		-L $(LIBFT) -L $(X11)

COMPILED =		fdf.o \
				display.o \
				get_next_line.o \
				helpers.o \
				parse.o

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB_FLAGS) -lft -lmlx -lXext -lX11 $(COMPILED)
	@echo "made" $(NAME)

$(COMPILED): %.o: %.c
	@$(CC) -c $(FLAGS) $(INC_FLAGS) $< -o $@

clean:
	@make -C $(LIBFT) clean
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@make -C $(LIBFT) fclean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all

