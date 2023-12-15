NAME    =	polymorph

CXX      =	c++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

HEADERS     =	Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			Brain.hpp

SRCS    =	Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			Brain.cpp \
			main.cpp

OBJS    =	$(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(HEADERS)

.PHONY: all clean fclean re
all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
