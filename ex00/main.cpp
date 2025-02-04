#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "--- Test 1: ---" << std::endl;
		Bureaucrat jim("Jim", 15);
		std::cout << jim << std::endl;
		jim.incrementGrade(5);
		std::cout << jim << std::endl;

		std::cout << "\n--- Test 2: ---" << std::endl;
		jim.incrementGrade(15); // Should throw
	}

	catch (const Bureaucrat::GradeTooHigh& value)
	{
		std::cout << "Exception caught: " << value.what() << std::endl;
	}

	catch (const Bureaucrat::GradeTooLow& value)
	{
		std::cout << "Exception caught: " << value.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "--- Test 3: ---" << std::endl;
		Bureaucrat dwight("Dwight", 15);
		std::cout << dwight << std::endl;
		dwight.decrementGrade(100);
		std::cout << dwight << std::endl;

		std::cout << "\n--- Test 4: ---" << std::endl;
		dwight.decrementGrade(50);
	}

	catch (const Bureaucrat::GradeTooHigh& value)
	{
		std::cout << "Exception caught: " << value.what() << std::endl;
	}

	catch (const Bureaucrat::GradeTooLow& value)
	{
		std::cout << "Exception caught: " << value.what() << std::endl;
	}

	return (0);
}
