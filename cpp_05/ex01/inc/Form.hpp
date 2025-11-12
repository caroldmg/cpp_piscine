#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		int	const			gradeToSign;
		int const			gradeToExec;
		bool				isSigned;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& org);
		~Form();

		Form& operator=(const Form &org);

		std::string getName() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		bool		getIsSigned() const;
		void		beSigned(Bureaucrat b);

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

std::ostream& operator<<(std::ostream &os, Form const &toPrint);