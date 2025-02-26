#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

static AForm* createShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* createRobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* createPresidentialForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formName, const std::string &target)
{
	int i = 0;

	std::string validNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm* (*createForms[3])(std::string) =
	{
		&createShrubberyForm, &createRobotomyForm, &createPresidentialForm
	};

	while (i < 3)
	{
		if (formName == validNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (createForms[i](target));
		}
		i++;
	}
	std::cout << "Form named: \"" << formName << "\" unknown. Can't create form." << std::endl;
	return (NULL);
}
