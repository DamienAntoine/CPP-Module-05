#ifndef __ROBOTOMYREQUESTFORM__
#define __ROBOTOMYREQUESTFORM__

#include <iostream>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("") {}
		RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45), _target(target) {}
		RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}
		~RobotomyRequestForm(){}

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		class NotSigned : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		const std::string	getTarget() const;
		virtual void		beSigned(const Bureaucrat &bureaucrat);
		virtual void		execForm(const Bureaucrat &bureaucrat) const;
};

#endif
