# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/23 12:51:23 by bvdhelen          #+#    #+#              #
#    Updated: 2026/08/04 16:07:36 by eldiaz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa
NAME = Array

# Compilador y banderas de compilación
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
INCLUDES = -I.

# Carpeta para objetos
OBJ_DIR = obj

# Definir códigos de color
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
GREY = \033[0;90m
RESET = \033[0m

# Archivos fuente y archivos objeto
SRCS = mymain.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREY)Compiling...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo
	@echo "$(GREEN)<<< CPP07-ex02 compiled >>>$(RESET)"
	@echo

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo
	@echo "$(CYAN)<<< clean complete >>>$(RESET)"
	@echo

fclean: clean
	@rm -rf $(NAME)
	@echo "$(BLUE)<<< full clean complete >>>$(RESET)"
	@echo

re: fclean all

.PHONY: all clean fclean re