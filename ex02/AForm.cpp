#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm"), _signGrade(0), _execGrade(0), _target(""), _signed(0)
{}

AForm::AForm(const std::string name, const int signGrade, const int execGrade, const std::string& target) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _target(target)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHigh();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLow();

	_signed = 0;
}

AForm::AForm(const AForm &other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _target(other._target), _signed(other._signed)
{}

AForm::~AForm()
{}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_signed = other._signed;
		_target = other._target;
	}
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= AForm::getSignGrade())
		_signed = 1;
	else
		throw GradeTooLow();
}

const char* AForm::GradeTooHigh::what() const throw()
{
	return ("grade too high!");
}

const char* AForm::GradeTooLow::what() const throw()
{
	return ("grade too low!");
}

const char* AForm::NotSigned::what() const throw()
{
	return("Form is not signed!");
}

void AForm::execForm(const Bureaucrat &bureaucrat) const
{
	if (!this->getSigned())
		throw NotSigned();

	if (bureaucrat.getGrade() > this->getExecGrade())
		throw GradeTooLow();

	this->execute();
}

std::ostream &operator<<(std::ostream &os, const AForm &aform)
{
	bool isSigned;

	isSigned = aform.getSigned();
	if (isSigned)
		os	<< aform.getName()
			<< "'s exec grade is " << aform.getExecGrade()
			<< " and sign grade is " << aform.getSignGrade()
			<< ". It has been signed." << std::endl;
	else
		os	<< aform.getName()
			<< "'s exec grade is " << aform.getExecGrade()
			<< " and sign grade is " << aform.getSignGrade()
			<< ". It has not been signed." << std::endl;
	return (os);
}

const std::string	AForm::getTarget() const
{
	return (_target);
}

