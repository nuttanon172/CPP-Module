NAME    =	fixedpoint

CC      =	c++

CPPFLAGS =	-Wall -Wextra -Werror -std=c++98

HEADERS     =	Fixed.hpp

SRCS    =	Fixed.cpp \
			main.cpp

OBJS    =	$(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(HEADERS)

.PHONY: all clean fclean re
all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
