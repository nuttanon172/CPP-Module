NAME    =	fixedpoint

CC      =	c++

CPPFLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS    =	Fixed.cpp \
			main.cpp

OBJS    =	$(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re
all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
