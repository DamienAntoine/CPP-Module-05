#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void	ShrubberyCreationForm::execute() const
{
	std::ofstream outfile((getTarget() + "_shrubbery").c_str());
	if (!outfile)
			throw FileError();

	outfile << "     ccee88oo" << std::endl;
	outfile << "  C8O8O8Q8PoOb o8oo" << std::endl;
	outfile << " dOB69QO8PdUOpugoO9bD" << std::endl;
	outfile << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
	outfile << "    6OuU  /p u gcoUodpP" << std::endl;
	outfile << "      \\\\\\//  /douUP" << std::endl;
	outfile << "        \\\\\\////" << std::endl;
	outfile << "         |||/\\" << std::endl;
	outfile << "         |||\\/" << std::endl;
	outfile << "         |||||" << std::endl;
	outfile << "   .....//||||\\...." << std::endl;
	outfile.close();
}

const char *ShrubberyCreationForm::FileError::what() const throw()
{
	return("Could not open file.");
}
