CC = c++
NAME = phonebook
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -std=c++98 -c

%.o: %.cpp
	$(CC) $(CFLAGS) $(SRCS);

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re