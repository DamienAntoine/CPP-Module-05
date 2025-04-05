#ifndef __ROBOTOMYREQUESTFORM__
#define __ROBOTOMYREQUESTFORM__

#include <iostream>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm() : AForm("Robotomy Request", 72, 45, ("")) {}
		RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45, target) {}
		RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}
		~RobotomyRequestForm(){}

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		virtual void execute() const;
};

#endif
