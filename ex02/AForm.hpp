#ifndef __FORM__
#define __FORM__

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;

	public:
		AForm(const std::string name, const int signGrade, const int execgrade);
		~AForm();

		class GradeTooHigh : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLow : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		std::string getName() const;
		virtual bool	getSigned() const;
		virtual int		getSignGrade() const;
		virtual int		getExecGrade() const;
		virtual void	beSigned(const Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const AForm& aform);

#endif
