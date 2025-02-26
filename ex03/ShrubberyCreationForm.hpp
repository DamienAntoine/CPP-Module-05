#ifndef __SHRUBBERYCREATIONFORM__
#define __SHRUBBERYCREATIONFORM__

#include <iostream>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("") {}
		ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}
		ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}
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

		virtual void		beSigned(const Bureaucrat &bureaucrat);
		const std::string	getTarget() const;
		virtual void		execForm(const Bureaucrat &bureaucrat) const;
};

#endif
