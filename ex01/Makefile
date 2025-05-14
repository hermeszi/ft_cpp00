# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myuen <myuen@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 16:53:29 by myuen             #+#    #+#              #
#    Updated: 2025/05/14 17:20:50 by myuen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = phonebook

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc

# Sources and objects
SRCS =	main.cpp \
		src/Contact.cpp src/PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Object compilation
src/%.o: src/%.cpp inc/Contact.hpp inc/PhoneBook.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
