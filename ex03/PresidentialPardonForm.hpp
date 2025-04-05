#ifndef __PRESIDENTIALPARDONFORM__
#define __PRESIDENTIALPARDONFORM__

#include <iostream>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5, ("")) {}
		PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5, target) {}
		PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}
		~PresidentialPardonForm(){}

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		virtual void execute() const;
};

#endif
