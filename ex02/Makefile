# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myuen <myuen@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 16:53:29 by myuen             #+#    #+#              #
#    Updated: 2025/05/17 15:46:55 by myuen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = account

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Sources and objects
SRCS =	tests.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Object compilation
src/test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

src/Account.o: Account.cpp Account.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
