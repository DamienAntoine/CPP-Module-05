#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void	PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		_signed = 1;
	else
		throw GradeTooLow();
}

void	PresidentialPardonForm::execForm(const Bureaucrat &bureaucrat) const
{
	if (!this->getSigned())
		throw NotSigned();
	if (bureaucrat.getGrade() > this->getExecGrade())
		throw GradeTooLow();

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const char *PresidentialPardonForm::NotSigned::what() const throw()
{
	return("Robotomy Request Form is not signed!");
}

const std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}
