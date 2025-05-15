# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myuen <myuen@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 16:53:29 by myuen             #+#    #+#              #
#    Updated: 2025/05/15 15:45:39 by myuen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = phonebook

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc

# Sources and objects
SRCS =	main.cpp \
		src/Contact.cpp \
		src/PhoneBook.cpp \
		src/ui_helper.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Object compilation
src/Contact.o: src/Contact.cpp inc/Contact.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

src/PhoneBook.o: src/PhoneBook.cpp inc/PhoneBook.hpp inc/Contact.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

src/ui_helper.o: src/ui_helper.cpp inc/ui_helper.hpp inc/PhoneBook.hpp inc/Contact.hpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp inc/PhoneBook.hpp inc/Contact.hpp inc/ui_helper.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
