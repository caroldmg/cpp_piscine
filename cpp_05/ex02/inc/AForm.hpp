#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	name;
		int	const			gradeToSign;
		int const			gradeToExec;
		bool				isSigned;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm& org);
		~AForm();

		AForm& operator=(const AForm &org);

		std::string getName() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		bool		getIsSigned() const;
		void		beSigned(Bureaucrat b);
		execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream &os, AForm const &toPrint);