NAME     := Bureaucrat
SRCS     := main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequest.cpp ShruberryCreationForm.cpp
OBJS     := $(SRCS:.cpp=.o)
CXX      := g++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "Project cleaned"

fclean: clean
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean format re
