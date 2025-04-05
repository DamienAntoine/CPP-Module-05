#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void	RobotomyRequestForm::execute() const
{
	std::cout << "~Brrrrrrrrrrrrrr~" << std::endl;
	srand((unsigned) time(NULL));
	int random = rand() % 2;
	if (random == 1)
		std::cout << this->getTarget() << " has been Robotomized." << std::endl;
	else if (random == 0)
		std::cout << "Robotomy failed." << std::endl;
}

