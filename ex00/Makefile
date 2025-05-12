# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myuen <myuen@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 16:53:29 by myuen             #+#    #+#              #
#    Updated: 2025/05/11 20:24:01 by myuen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = megaphone

# Project source files
SRCS =	megaphone.cpp

# Object directory and object files
OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Compile and link your program with the libraries
all: $(NAME)

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Rule to compile object files into the obj directory
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files only
clean:
	rm -f $(OBJS)

# Clean up all object files, libraries, and remove obj directory
fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re
