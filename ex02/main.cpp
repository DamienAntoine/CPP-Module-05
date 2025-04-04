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
		Bureaucrat michael("Michael", 1);
		Bureaucrat ryan("Ryan", 140);

		try
		{
			Bureaucrat invalid("Invalid", 151);
			std::cout << invalid.getName() << " created successfully." << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Failed to create invalid bureaucrat: " << e.what() << std::endl;
		}

		ShrubberyCreationForm shrub("Garden");
		RobotomyRequestForm robot("Dwight");
		PresidentialPardonForm pardon("Jim");
		std::cout << std::endl;

		std::cout << "*** Test 1: Sign forms ***" << std::endl;
		michael.signForm(shrub);
		ryan.signForm(shrub);

		std::cout << std::endl;

		michael.signForm(robot);
		ryan.signForm(robot);

		std::cout << std::endl;

		michael.signForm(pardon);
		ryan.signForm(pardon);

		std::cout << std::endl;

		std::cout << "*** Test 2: Execute forms ***" << std::endl;
		michael.executeForm(shrub);
		ryan.executeForm(shrub);
		std::cout << std::endl;
		michael.executeForm(robot);
		ryan.executeForm(robot);
		std::cout << std::endl;
		michael.executeForm(pardon);
		ryan.executeForm(pardon);
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
