SRCS = main.cpp\
		Cat.cpp\
		Animal.cpp\
		Dog.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp\


OBJ = $(SRCS:.cpp=.o)
CPP = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Polymorphism
HEAD = Animal.hpp\
		Cat.hpp\
		Dog.hpp\
		WrongAnimal.hpp\
		WrongCat.hpp\

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