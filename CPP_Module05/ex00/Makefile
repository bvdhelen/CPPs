# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/05 14:18:57 by bvdhelen          #+#    #+#              #
#    Updated: 2026/07/05 14:20:12 by bvdhelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa
NAME = Bureaucrat

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
SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(SRCS)
	@echo "$(GREY)Compiling...$(RESET)"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRCS)
	@echo
	@echo "$(GREEN)<<< CPP05-ex00 compiled >>>$(RESET)"
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