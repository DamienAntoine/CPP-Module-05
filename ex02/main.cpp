#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		std::cout << "--- Test 1: Valid Form Creation ---" << std::endl;
		AForm form1("Tax Form", 50, 25);
		std::cout << form1 << std::endl;

		std::cout << "\n--- Test 2: Bureaucrat Can Sign ---" << std::endl;
		Bureaucrat andy("Andy", 45);
		std::cout << andy << std::endl;
		andy.signForm(form1);
		std::cout << form1 << std::endl;

		std::cout << "\n--- Test 3: Bureaucrat Cannot Sign ---" << std::endl;
		Bureaucrat ryan("Ryan", 100);
		std::cout << ryan << std::endl;
		ryan.signForm(form1);
	}
	catch (const AForm::GradeTooHigh& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLow& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Invalid Form Creation ---" << std::endl;
	try
	{
		AForm form2("Invalid Form", 0, 25);
	}
	catch (const AForm::GradeTooHigh& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		AForm form3("Invalid Form", 50, 151);
	}
	catch (const AForm::GradeTooLow& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
