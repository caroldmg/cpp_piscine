#pragma once
# include <iostream>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat
{
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& org);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat &org);

		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

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

std::ostream& operator<<(std::ostream &os, Bureaucrat const &toPrint);