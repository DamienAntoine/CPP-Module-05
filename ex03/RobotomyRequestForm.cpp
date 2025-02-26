#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void	RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		_signed = 1;
	else
		throw GradeTooLow();
}

void	RobotomyRequestForm::execForm(const Bureaucrat &bureaucrat) const
{
	if (!this->getSigned())
		throw NotSigned();
	if (bureaucrat.getGrade() > this->getExecGrade())
		throw GradeTooLow();

	std::cout << "~Brrrrrrrrrrrrrr~" << std::endl;
	srand((unsigned) time(NULL));
	int random = rand() % 2;
	if (random == 1)
		std::cout << this->getTarget() << " has been Robotomized." << std::endl;
	else if (random == 0)
		std::cout << "Robotomy failed." << std::endl;
}

const char *RobotomyRequestForm::NotSigned::what() const throw()
{
	return("Robotomy Request Form is not signed!");
}

const std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}
