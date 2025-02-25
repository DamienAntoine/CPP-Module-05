#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 140);

		try
		{
			Bureaucrat invalid("Invalid", 151);
			std::cout << invalid.getName() << " created successfully." << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Failed to create invalid bureaucrat: " << e.what() << std::endl;
		}

		ShrubberyCreationForm shrub("Garden");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Criminal");
		std::cout << std::endl;
		// Sign forms
		boss.signForm(shrub);
		intern.signForm(shrub);

		std::cout << std::endl;

		boss.signForm(robot);
		intern.signForm(robot);

		std::cout << std::endl;

		boss.signForm(pardon);
		intern.signForm(pardon);

		std::cout << std::endl;

		// Execute forms
		boss.execForm(shrub);
		intern.execForm(shrub);
		std::cout << std::endl;
		boss.execForm(robot);
		intern.execForm(robot);
		std::cout << std::endl;
		boss.execForm(pardon);
		intern.execForm(pardon);
		std::cout << std::endl;
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
