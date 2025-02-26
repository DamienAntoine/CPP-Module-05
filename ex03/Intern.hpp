#ifndef __INTERN__
#define __INTERN__

#include <iostream>

class AForm;

class Intern
{
	public:
		Intern(){}
		Intern(const Intern& other);
		~Intern(){}
		Intern& operator=(const Intern& other);

		AForm* makeForm(std::string formName, const std::string &target);
};

#endif
