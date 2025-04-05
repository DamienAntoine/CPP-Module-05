#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	try
	{
		Bureaucrat michael("Michael", 1);

		std::cout << "*** Test 1: Valid Form Creation ***" << std::endl;
		AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Garden");
		AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Robot");
		AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Ryan");
		std::cout << std::endl;

		std::cout << "*** Test 2: Invalid Form Creation ***" << std::endl;
		AForm* invalidForm = someRandomIntern.makeForm("invalid request", "Employee");
		if (invalidForm == NULL)
			std::cout << "Invalid form was not created" << std::endl;
		std::cout << std::endl;

		std::cout << "*** Test 3: Testing Forms ***" << std::endl;
		if (shrubberyForm)
		{
			michael.signForm(*shrubberyForm);
			michael.executeForm(*shrubberyForm);
			delete shrubberyForm;
		}
		std::cout << std::endl;

		if (robotomyForm)
		{
			michael.signForm(*robotomyForm);
			michael.executeForm(*robotomyForm);
			delete robotomyForm;
		}
		std::cout << std::endl;

		if (pardonForm)
		{
			michael.signForm(*pardonForm);
			michael.executeForm(*pardonForm);
			delete pardonForm;
		}
	}
	catch (const AForm::GradeTooHigh& e)
	{
		std::cout << "GradeTooHigh exception: " << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLow& e)
	{
		std::cout << "GradeTooLow exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Other exception: " << e.what() << std::endl;
	}
	return 0;
}

/*
//subject test:
int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		std::cout << "Form created: " << rrf->getName() << std::endl;
		delete rrf;
	}

	return 0;
}*/
