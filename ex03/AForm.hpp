#ifndef __FORM__
#define __FORM__

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		const int _signGrade;
		const int _execGrade;

	protected:
		bool _signed;

	public:
		AForm();
		AForm(const std::string name, const int signGrade, const int execgrade);
		AForm(const AForm &other);
		virtual ~AForm();

		AForm& operator=(const AForm &other);

		class GradeTooHigh : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLow : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		std::string		getName() const;
		virtual bool	getSigned() const;
		virtual int		getSignGrade() const;
		virtual int		getExecGrade() const;

		virtual void	beSigned(const Bureaucrat &bureaucrat);
		virtual void	execForm(const Bureaucrat &bureaucrat) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& aform);

#endif
