#ifndef __FORM__
#define __FORM__

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	public:
		Form();
		Form(const std::string name, const int signGrade, const int execgrade);
		Form(const Form& other);
		~Form();

		Form& operator=(const Form &other);

		class GradeTooHigh : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLow : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		std::string getName() const;
		bool	getSigned() const;
		int		getSignGrade() const;
		int		getExecGrade() const;
		void	beSigned(const Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
