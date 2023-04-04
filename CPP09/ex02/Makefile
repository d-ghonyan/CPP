UNAME = $(shell uname -s)
CXX = c++
NAME = PmergeMe
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror #-fsanitize=address -g3 

ifneq ($(UNAME), Darwin)
	CXXFLAGS = -fsanitize=address -g3 -std=c++11
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(NAME).exe

re: fclean all

.PHONY: all clean fclean re