NAME    =	harlFilter

CC      =	c++

CPPFLAGS =	-Wall -Wextra -Werror -std=c++98

HEADERS     =	Harl.hpp

SRCS    =	main.cpp \
			Harl.cpp

OBJS    =	$(SRCS:.cpp=.o)

$(NAME): $(OBJS) $(INC)
	$(CC) $(CPPFLAGS) $(INC) $(OBJS) -o $(NAME)

$(OBJS): $(HEADERS)

.PHONY: all clean fclean re
all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
