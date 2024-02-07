NAME      = polymorph

CXX       = c++

CXXFLAGS  = -Wall -Wextra -Werror -std=c++98

OBJ_DIR   = obj

HEADERS     =	Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			Brain.hpp

SRCS    =	Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			Brain.cpp \
			main.cpp

OBJS      = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean fclean re
all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
