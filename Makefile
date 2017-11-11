# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atverdok <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/05 21:08:04 by atverdok          #+#    #+#              #
#    Updated: 2017/11/05 21:08:08 by atverdok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CC = clang++

SRC = src

OBJ = obj

CFLAGS = -Wall -Wextra -Werror -I./includes

NCURSES = -lncurses

SRCS =	  main.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(NCURSES)

%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all
