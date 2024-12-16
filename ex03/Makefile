NAME= ex03

CXX= c++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98 #-g

SRC= main.cpp AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJ_DIR= objects
OBJ= $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re