# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 18:39:39 by abel-hid          #+#    #+#              #
#    Updated: 2024/02/07 18:43:47 by abel-hid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp\

OBJ = $(SRCS:.cpp=.o)
CPP = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = array
HEAD = Array.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEAD)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all