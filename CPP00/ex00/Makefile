NAME    =	megaphone

CC      =	c++

CPPFLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS    =	megaphone.cpp

OBJS    =	$(addprefix bin/,$(SRCS:.cpp=.o))

$(NAME): bin $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

bin/%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

.PHONY: all clean fclean re bin
all: $(NAME)

clean:
	@rm -rf bin

fclean: clean
	@rm -f $(NAME)

re: fclean all

bin:
	@mkdir -p bin
