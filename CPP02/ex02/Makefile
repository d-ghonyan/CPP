UNAME = $(shell uname -s)
CXX = c++
NAME = fixed
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

ifneq ($(UNAME), Darwin)
	CXXFLAGS = -Wall -Wextra -Werror -std=c++11
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