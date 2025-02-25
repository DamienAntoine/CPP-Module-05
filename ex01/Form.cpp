#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("FormX"), _signed(0), _signGrade(1), _execGrade(1)
{}

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHigh();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLow();

	_signed = 0;
	std::cout << _name << " form created." << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{}

Form::~Form()
{
	std::cout << this->_name << " destroyed." << std::endl;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
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
	return ("grade too high!");
}

const char* Form::GradeTooLow::what() const throw()
{
	return ("grade too low!");
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
