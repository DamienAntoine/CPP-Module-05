#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHigh();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLow();

	_signed = 0;
	std::cout << _name << " form created." << std::endl;
}

Form::~Form()
{
	std::cout << this->_name << " destroyed." << std::endl;
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= Form::getSignGrade())
		_signed = 1;
	else
		throw GradeTooLow();
}

const char* Form::GradeTooHigh::what() const throw()
{
	return ("Form grade too high!");
}

const char* Form::GradeTooLow::what() const throw()
{
	return ("Form grade too low!");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	bool isSigned;

	isSigned = form.getSigned();
	if (isSigned)
		os	<< form.getName()
			<< "'s exec grade is " << form.getExecGrade()
			<< " and sign grade is " << form.getSignGrade()
			<< ". It has been signed." << std::endl;
	else
		os	<< form.getName()
			<< "'s exec grade is " << form.getExecGrade()
			<< " and sign grade is " << form.getSignGrade()
			<< ". It has not been signed." << std::endl;
	return (os);
}
