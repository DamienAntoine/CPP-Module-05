#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("BureaucratX")
{}

Bureaucrat::Bureaucrat(const std::string name, int grade)  : _name(name)
{
	if (grade < 1)
		throw GradeTooHigh();
	if (grade > 150)
		throw GradeTooLow();
	_grade = grade;
	std::cout << _name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name << " destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::incrementGrade(int amount)
{
	if (_grade - amount < 1)
		throw GradeTooHigh();
	_grade -= amount;
}

void Bureaucrat::decrementGrade(int amount)
{
	if (_grade + amount > 150)
		throw GradeTooLow();
	_grade += amount;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& value)
	{
		std::cout << _name << " couldn't sign " << form.getName()
				<< " because " << value.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHigh::what() const throw()
{
	return ("Grade too high !");
}

const char *Bureaucrat::GradeTooLow::what() const throw()
{
	return ("Grade too Low !");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
