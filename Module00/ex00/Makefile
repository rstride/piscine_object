# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Name of the output program
NAME = bank_app

# Source files
SRCS = main.cpp Bank.cpp Account.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(NAME)

# Linking the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Rule for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

# Full clean: remove object files and executable
fclean: clean
	rm -f $(NAME)

# Recompile everything
re: fclean all

# Rule to ensure make doesn't delete the intermediate files automatically
.PHONY: all clean fclean re
