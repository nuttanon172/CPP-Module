NAME    =	zombie

CC      =	c++

CPPFLAGS =	-Wall -Wextra -Werror -std=c++98

INC     =	Zombie.hpp

SRCS    =	main.cpp \
			newZombie.cpp \
			randomChump.cpp \
			Zombie.cpp

OBJS    =	$(SRCS:.cpp=.o)

$(NAME): $(OBJS) $(INC)
	$(CC) $(CPPFLAGS) $(INC) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re
all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
