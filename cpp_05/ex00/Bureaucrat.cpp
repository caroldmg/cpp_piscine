#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(MIN_GRADE)
{
	std::cout << "Bureaucrat default created " << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): name(name)
{
	this->grade = MIN_GRADE;
	std::cout << "Bureaucrat " << this->name << " created " << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	if (grade < MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = grade;
	std::cout << "Bureaucrat " << this->name << " created " << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat eliminated" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& org) : name(org.name)
{
	*this = org;
}

// OPERADORES

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &org)
{
	const_cast<std::string&>(this->name) = org.getName();
	if (this != &org)
	{
        this->grade = org.getGrade();
    }
	std::cout << "Copy Assigment operator called" << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &toPrint)
{
	os << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade();
	return (os);
}

// MÉTODOS DE CLASE

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade == MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	grade++;
}

// EXCEPTIONS

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("⚠️ GRADE TOO HIGH ⚠️");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("⚠️ GRADE TOO LOW ⚠️");
}