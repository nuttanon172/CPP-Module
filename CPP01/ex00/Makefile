NAME	=	megaphone

CC	=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC	=	megaphone.cpp

OBJ	=	$(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

.PHONY: all clean fclean re
all: $(NAME)

clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: fclean all
