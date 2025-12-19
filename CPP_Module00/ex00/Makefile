NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re