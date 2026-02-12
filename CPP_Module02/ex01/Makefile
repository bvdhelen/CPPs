# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/04 17:54:53 by eldiaz-c          #+#    #+#              #
#    Updated: 2026/01/04 17:54:53 by eldiaz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa
NAME = fixed_point

# Compilador y banderas de compilación
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# Definir códigos de color
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN =  \033[0;36m
WHITE = \033[0;37m
GREY = \033[0;90m
RESET = \033[0m

# Archivos fuente y archivos objeto
SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(SRCS)
	@echo "$(GREY)Compiling...$(RESET)"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRCS)
	@echo
	@echo "$(GREEN)<<< CPP02-ex01 compiled >>>$(RESET)"
	@echo

clean:
	@rm -rf $(OBJS)
	@echo
	@echo "$(CYAN)<<< clean complete >>>$(RESET)"
	@echo

fclean: clean
	@rm -rf $(NAME)
	@echo "$(BLUE)<<< full clean complete >>>$(RESET)"
	@echo
	
re: fclean all

.PHONY: all clean fclean re