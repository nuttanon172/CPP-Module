NAME = bureaucrat

CXX = c++

CXXFLAGS = -WAll -Wextra -Werror -std=c++98

OBJ_DIR = obj;

HEADERS = Bureaucrat.hpp

SRCS = Bureaucrat.cpp

OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, %(SRCS))

$(NAME): $(OBJS)
	