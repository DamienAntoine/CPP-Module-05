#ifndef __SHRUBBERYCREATIONFORM__
#define __SHRUBBERYCREATIONFORM__

#include <iostream>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm() : AForm("default", 145, 137){}
		ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137){}
		ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other){}
		~ShrubberyCreationForm(){}

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		class NotSigned : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class FileError : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		virtual void	beSigned(const Bureaucrat &bureaucrat);
		void			execForm(const Bureaucrat &bureaucrat);
};

#endif
