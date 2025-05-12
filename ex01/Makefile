# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myuen <myuen@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 16:53:29 by myuen             #+#    #+#              #
#    Updated: 2025/05/12 19:19:25 by myuen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = phonebook

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

# Libraries and includes
INC_DIR = inc
INC = -I$(INC_DIR)

# Header files
HEADERS = $(INC_DIR)/Contact.hpp $(INC_DIR)/PhoneBook.hpp 

# Directories
OBJ_DIR = obj
SRC_DIRS = src

# Source files
SRCS = src/PhoneBook.cpp src/Contact.cpp
MAIN_SRC = main.cpp

# Object files
OBJS = $(SRCS:src/%.cpp=$(OBJ_DIR)/%.o)
MAIN_OBJ = $(OBJ_DIR)/main.o

# Variable definitions
DEPS = $(OBJS:.o=.d) $(MAIN_OBJ:.o=.d)

# Create obj directories string for creation
OBJ_DIRS = $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SRC_DIRS:src/%=%))

# Rules
all: $(NAME)

# Create object directories
$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

$(MAIN_OBJ): $(MAIN_SRC) $(HEADERS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INC) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: src/%.cpp $(HEADERS) | $(OBJ_DIRS)
	$(CXX) $(CXXFLAGS) $(INC) -MMD -MP -c $< -o $@

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $(OBJS) $(MAIN_OBJ) -o $(NAME)

# Include generated dependency files
-include $(DEPS)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Remake everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re