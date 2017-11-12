#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skavunen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 17:32:33 by skavunen          #+#    #+#              #
#    Updated: 2017/11/12 21:12:37 by skavunen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_gkrellm

SRCS =	main.cpp \
		CpuModule.cpp \
		CursDisplay.cpp \
		DateModule.cpp \
		GraficDisplay.cpp \
		HostUserModule.cpp \
		MemoryModule.cpp \
		NetworkModule.cpp \
		OsInfoModule.cpp \

CPP = clang++
CC_FLAGS = -Wall -Werror -Wextra

OBJ = $(SRCS:.cpp=.o)

NOC=\033[0m
OKC=\033[32;05m
ERC=\033[31m
WAC=\033[33m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(OKC)$(NAME): Compiling objectives $(NAME)$(NOC)"
	@$(CPP) $(CC_FLAGS) -o $(NAME) $(OBJ) -I ~/.brew/include -L ~/.brew/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio -rpath ~/.brew/lib -lncurses
	@echo "$(OKC)$(NAME): Compilation success!$(NOC)"

%.o: %.cpp
	@$(CPP) $(CC_FLAGS) -I ~/.brew/include -o $@  -c $^

clean:
	@rm -rf $(OBJ)
	@echo "$(WAC)$(NAME): Removing $(NAME) objectives$(NOC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(WAC)$(NAME): Removing executable$(NOC)"

re: fclean all