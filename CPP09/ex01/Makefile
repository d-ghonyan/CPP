UNAME = $(shell uname -s)
CXX = c++
NAME = RPN
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
SANITIZE = -fsanitize=address -g3
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

ifneq ($(UNAME), Darwin)
	CXXFLAGS = -Wall -Wextra -Werror -std=c++11 $(SANITIZE)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(SANITIZE) $(OBJS) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(NAME).exe

re: fclean all

.PHONY: all clean fclean re