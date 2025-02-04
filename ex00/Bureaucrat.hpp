#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();

		void incrementGrade(int grade);
		void decrementGrade(int grade);

		class GradeTooHigh : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLow : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		const std::string getName() const;
		int getGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
