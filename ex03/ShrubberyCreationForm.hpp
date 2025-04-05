#ifndef __SHRUBBERYCREATIONFORM__
#define __SHRUBBERYCREATIONFORM__

#include <iostream>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137, "") {}
		ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137, target) {}
		ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}
		~ShrubberyCreationForm(){}

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		class FileError : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		protected:
			virtual void execute() const;
};

#endif
