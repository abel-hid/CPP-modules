# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 18:19:52 by abel-hid          #+#    #+#              #
#    Updated: 2023/11/08 21:03:37 by abel-hid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp\
	AMateria.cpp\
	Character.cpp\
	Cure.cpp\
	Ice.cpp\
	MateriaSource.cpp\
	
OBJ = $(SRCS:.cpp=.o)
CPP = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = interface
HEAD = AMateria.hpp\
	ICharacter.hpp\
	IMateriaSource.hpp\
	Character.hpp\
	MateriaSource.hpp\
	Ice.hpp\
	Cure.hpp\

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp 
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all