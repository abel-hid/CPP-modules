SRCS = main.cpp \
		HumanA.cpp \
		Weapon.cpp \
		HumanB.cpp 

OBJ = $(SRCS:.cpp=.o)
CPP = c++
RM = rm -f
header = Weapon.hpp HumanA.hpp HumanB.hpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = unnecessary_violence

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(header)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
