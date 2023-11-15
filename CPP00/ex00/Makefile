NAME	=	megaphone

CC	=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC	=	megaphone.cpp

OBJS	=	$(SRC:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re
all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
