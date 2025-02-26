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

		// valid forms tests
		AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Garden");
		AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Robot");
		AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Ryan");
		std::cout << std::endl;

		// invalid form test
		AForm* invalidForm = someRandomIntern.makeForm("invalid request", "Employee");
		if (invalidForm == NULL)
			std::cout << "Invalid form was correctly not created" << std::endl;
		std::cout << std::endl;

		// testing created forms
		if (shrubberyForm)
		{
			michael.signForm(*shrubberyForm);
			michael.execForm(*shrubberyForm);
			delete shrubberyForm;
		}
		std::cout << std::endl;

		if (robotomyForm)
		{
			michael.signForm(*robotomyForm);
			michael.execForm(*robotomyForm);
			delete robotomyForm;
		}
		std::cout << std::endl;

		if (pardonForm)
		{
			michael.signForm(*pardonForm);
			michael.execForm(*pardonForm);
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
