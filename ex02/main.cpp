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
		// Sign forms
		michael.signForm(shrub);
		ryan.signForm(shrub);

		std::cout << std::endl;

		michael.signForm(robot);
		ryan.signForm(robot);

		std::cout << std::endl;

		michael.signForm(pardon);
		ryan.signForm(pardon);

		std::cout << std::endl;

		// Execute forms
		michael.execForm(shrub);
		ryan.execForm(shrub);
		std::cout << std::endl;
		michael.execForm(robot);
		ryan.execForm(robot);
		std::cout << std::endl;
		michael.execForm(pardon);
		ryan.execForm(pardon);
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
