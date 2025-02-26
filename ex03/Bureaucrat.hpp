#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		void	incrementGrade(int grade);
		void	decrementGrade(int grade);
		void	signForm(AForm& aform);
		void	execForm(AForm const & form);

		class GradeTooHigh : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLow : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		const std::string	getName() const;
		int					getGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
