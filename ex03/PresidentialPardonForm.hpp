#ifndef __PRESIDENTIALPARDONFORM__
#define __PRESIDENTIALPARDONFORM__

#include <iostream>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("") {}
		PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {}
		PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {}
		~PresidentialPardonForm(){}

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		class NotSigned : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		const std::string	getTarget() const;
		virtual void		beSigned(const Bureaucrat &bureaucrat);
		virtual void		execForm(const Bureaucrat &bureaucrat) const;

};

#endif
