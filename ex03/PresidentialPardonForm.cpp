#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void	PresidentialPardonForm::execute() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

