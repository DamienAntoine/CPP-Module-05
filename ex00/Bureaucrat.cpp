#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade)  : _name(name)
{
	if (grade < 1)
		throw GradeTooHigh();
	if (grade > 150)
		throw GradeTooLow();
	_grade = grade;
	std::cout << _name << " created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name << " destroyed" << std::endl;
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
